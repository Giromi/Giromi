import socket
import threading
import pyautogui  # 파워포인트 슬라이드 제어를 위해 사용
import tkinter as tk
from tkinter import ttk

# 서버 설정
HOST = '0.0.0.0'  # 모든 네트워크 인터페이스에서 수신
PORT = 12345

def send_all_clients(message):
    for client_socket, addr in clients:
        try:
            client_socket.send(message.encode('utf-8'))
        except Exception as e:
            print(f"Error sending to {addr}: {e}")

def handle_client(client_socket, addr):
    try:
        # 🔥 클라이언트 주소 정보 전송
        client_socket.send(f"{addr[0]}:{addr[1]}".encode('utf-8'))
        print(f"Client {addr} connected.")

        # 클라이언트와 지속적으로 통신
        while True:
            message = client_socket.recv(1024).decode('utf-8')
            if not message:
                break
            print(f"Received from {addr}: {message}")

            if message == "NEXT":
                pyautogui.press('right')  # 슬라이드 다음으로
            elif message == "PREV":
                pyautogui.press('left')  # 슬라이드 이전으로
            elif message == "EXIT":
                print(f"Client {addr} requested to close the connection.")
                break  # 연결 종료
            else:
                print(f"Unknown command from {addr}: {message}")

    except Exception as e:
        print(f"Error with client {addr}: {e}")
    finally:
        client_socket.close()
        try:
            clients.remove((client_socket, addr))
            print(f"Removed {addr} from clients list.")
        except ValueError:
            print(f"{addr} not in clients list.")


# 클라이언트 리스트 업데이트 함수
def update_client_list(tree):
    # 기존 리스트 초기화
    for item in tree.get_children():
        tree.delete(item)
    # 현재 클라이언트 리스트 추가
    for _, addr in clients:
        tree.insert("", "end", values=(addr[0], addr[1]))

# 서버 시작 함수
def start_server(tree):
    try:
        server_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
        server_socket.bind((HOST, PORT))
        server_socket.listen()
        print(f"Server started on {HOST}:{PORT}")
    except Exception as e:
        print(f"Error starting server: {e}")
        root.destroy()  # GUI 종료
        exit(1)  # 프로그램 종료
    while not shutdown_event.is_set():
        try:
           server_socket.settimeout(1)  # 🔥 타임아웃 설정
           client_socket, addr = server_socket.accept()
           print(f"Connected by {addr}")
           clients.append((client_socket, addr))
           update_client_list(tree)  # GUI 업데이트
           client_thread = threading.Thread(target=handle_client, args=(client_socket, addr), daemon=True)
           client_thread.start()
        except socket.timeout:
            continue
        except Exception as e:
           print(f"Error accepting connection: {e}")
           break
    server_socket.close()
    print("Server socket closed.")

# 서버 GUI 생성
def create_gui():
    global clients, root, server_socket, shutdown_event
    clients = []
    server_socket = None
    root = tk.Tk()
    root.title("Slide Remote Server")
    root.geometry("800x600")

    frame = ttk.Frame(root)
    frame.pack(pady=10)

    tree = ttk.Treeview(frame, columns=("IP Address", "Port"), show="headings")
    tree.heading("IP Address", text="IP Address")
    tree.heading("Port", text="Port")
    tree.pack()

    server_thread = threading.Thread(target=start_server, args=(tree,), daemon=True)
    server_thread.start()
    shutdown_event = threading.Event()

    def on_close():
        print("Shutting down server...")
        shutdown_event.set() 
        server_thread.join() 
        root.destroy()

    root.protocol("WM_DELETE_WINDOW", on_close)
    root.mainloop()

if __name__ == "__main__":
    create_gui()
