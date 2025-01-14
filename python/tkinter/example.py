
import tkinter as tk

# 루트 윈도우 생성
window = tk.Tk()
window.title("Hello Tkinter")  # 윈도우 제목 설정
# window.geometry("300x100")     # 윈도우 크기 설정
#
# # 레이블 생성 및 배치
label = tk.Label(window, text="Hello, World!")
label.pack()  # 위아래 여백 설정

# 이벤트 루프 시작
window.mainloop()
