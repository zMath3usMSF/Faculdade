nomes = ["Ana", "Carlos", "Tafarel", "Maria"]
for i in range(len(nomes)):
    print(nomes[i])

def CalcularMedia(notas):
    media = 0
    for i in range(len(notas)):
        media += notas[i]
    return media / len(notas)

print(CalcularMedia([5, 8, 6, 5]))