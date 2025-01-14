import socket
import tkinter as tk

# 서버 연결 설정
HOST = '10.210.60.45'  # 팀장의 IP 주소
PORT = 12345


# 서버에 메시지 보내기
def send_command(command):
    try:
        client_socket.send(command.encode('utf-8'))
        log_message(f"Sent: {command}")
    except Exception as e:
        log_message(f"Error: {e}")

# 프로그램 종료 시 소켓 닫기
def on_close():
    try:
        client_socket.send("EXIT".encode('utf-8'))  # 종료 메시지 전송
        client_socket.close()
        print("Socket closed.")
    except Exception as e:
        print(f"Error closing socket: {e}")
    root.destroy()

# 로그 메시지 출력 함수
def log_message(message):
    text_widget.insert(tk.END, message + '\n')
    text_widget.see(tk.END)  # 자동 스크롤

# GUI 설정
def create_gui():
    global client_socket, root, text_widget

    # GUI 창 설정
    root = tk.Tk()
    root.title("Slide Remote Controller")
    root.protocol("WM_DELETE_WINDOW", on_close)  # 창 닫을 때 소켓 닫기

    # 로그 출력 텍스트 위젯
    text_widget = tk.Text(root, height=10, width=50)
    text_widget.pack(pady=10)
    text_widget.insert(tk.END, "Slide Remote Controller\n")

    # 소켓 연결 시도
    client_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    try:
        client_socket.connect((HOST, PORT))
        log_message(f'Connected to the server.')

        addr_info = client_socket.recv(1024).decode('utf-8')
        log_message(f"Server Response: {addr_info}")

    except Exception as e:
        print(f"Error connecting to the server: {e}")
        log_message(f"Error: {e}")
        return

    # 이전 버튼
    btn_prev = tk.Button(root, text="Previous Slide", command=lambda: send_command("PREV"), width=20, height=2)
    btn_prev.pack(pady=10)

    # 다음 버튼
    btn_next = tk.Button(root, text="Next Slide", command=lambda: send_command("NEXT"), width=20, height=2)
    btn_next.pack(pady=10)

    root.mainloop()

if __name__ == "__main__":
    create_gui()
