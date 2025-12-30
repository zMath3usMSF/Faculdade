import tkinter as tk

def atualizar_coordenadas(event):
    x = event.x
    y = event.y
    label_coordenadas["text"] = f"Coordenadas do mouse: X{x}, Y={y}"

janela = tk.Tk()
janela.title("Tratamento de Eventos - Coordenadas do Mouse")

label_coordenadas = tk.Label(janela, text="Mova o mouse sobre a janela para ver as coordenadas")
label_coordenadas.pack(padx=200, pady=200)

janela.bind("<Motion>", atualizar_coordenadas)

janela.mainloop()