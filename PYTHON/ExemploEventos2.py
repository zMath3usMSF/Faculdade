import tkinter as tk

def capturar_clic(event):
    x = event.x
    y = event.y
    label_coordenadas["text"] = f"Último clique: X={x}, Y={y}"

janela = tk.Tk()
janela.title("Tratamento de Eventos - Captura de Cliquei Esquerdo")

label_coordenadas = tk.Label(janela, text="Clique em qualquer lugar da janela")
label_coordenadas.pack(padx=200, pady=100)

janela.bind("<Button-1>", capturar_clic)

janela.mainloop()