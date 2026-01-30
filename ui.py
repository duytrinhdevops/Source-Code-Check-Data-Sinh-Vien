import tkinter as tk
import subprocess
import os
import sys

def resource_path(relative_path):
    try:
        base_path = sys._MEIPASS
    except Exception:
        base_path = os.path.abspath(".")
    return os.path.join(base_path, relative_path)

core_path = resource_path("core.exe")

root = tk.Tk()
root.title("TOOL SEARCH DATA _ DATA ANALYSIS SV UNETI K19 _ CODE BY DUYTRINH (UI PYTHON + CORE C++)")

tk.Label(
    root,
    text="SEARCH SINH VIEN THEO THONG TIN UNETI K19 _ TOOL BY DUYTRINH",
    font=("Arial", 13, "bold")
).grid(row=0, column=0, columnspan=3, sticky='w', pady=5)

option = tk.StringVar()
option.set("1")

tk.OptionMenu(
    root,
    option,
    "1 - Search Họ Tên",
    "2 - Search Mã Sinh Viên",
    "3 - Search Lớp",
    "4 - Search First Name",
    "5 - Search Ngày Tháng Năm Sinh",
    "6 - Search Nơi Sinh",
    "7 - Search Dân Tộc",
    "8 - Search Ngày Sinh",
    "9 - Seach Tháng Sinh",
    "10 - Search Năm Sinh",
    "11 - Tỉ Lê Năm Sinh",
    "12 - Tỉ Lệ Nơi Sinh",
    "13 - Tỉ Lệ Dân Tộc",
    "14 - Tỉ Lệ Giới Tính",
    "15 - ANALYSIS Nơi Sinh",
    "16 - ANALYSIS Dân Tộc",
    "17 - ANALYSIS Năm Sinh",
    "18 - ANALYSIS Phân Bổ SV_Lớp"
).grid(row=1, column=0, sticky='w')

tk.Label(root, text="NHẬP THÔNG TIN").grid(row=1, column=0, sticky='w', padx=220)

entry1 = tk.Entry(root, width=30)
entry1.grid(row=1, column=0, padx=330, sticky='w')

def check():
    data_in = entry1.get().strip()
    cmd = option.get().split()[0]
    
    result = subprocess.run(
        [core_path, cmd, data_in],
        capture_output=True,
        text=True,
        encoding="utf-8"
    )
    

    text_result.delete("1.0", tk.END)
    text_result.insert(tk.END, result.stdout)

tk.Button(root, text="Search Infor", command=check).grid(
    row=1, column=0, padx=530, sticky='w'
)

header = "Mã SV                      |                          Họ Tên                           |        Giới Tính       |             Lớp                 |         Ngày Sinh         |           Dân Tộc              |           Nơi Sinh                    |     Cơ Sở         "
tk.Label(root, text=header, anchor='w').grid(
    row=3, column=0, columnspan=3, sticky='w'
)

text_result = tk.Text(root, height=30, width=120)
text_result.grid(row=4, column=0, columnspan=3, sticky='w')
tk.Label(root, text=" @Copyright : Created by DuyTrinh _ 09/01/2026", anchor='w').grid(
    row=5, column=0, sticky='w'
)
root.mainloop()
