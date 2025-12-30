import math

def calcular_raizes(a, b, c):
    delta = b ** 2 - 4 * a * c

    if delta > 0:
        raiz1 = (-b + math.sqrt(delta)) / (2 * a)
        raiz2 = (-b - math.sqrt(delta)) / (2 * a)
        return (raiz1, raiz2)
    elif delta == 0:
        raiz = -b / (2 * a)
        return (raiz)
    else:
        parte_real = -b / (2 * a)
        parte_imaginaria = math.sqrt(-delta) / (2 * a)
        raiz1 = complex(parte_real, parte_imaginaria)
        raiz2 = complex(parte_real, -parte_imaginaria)
        return (raiz1, raiz2)
    
a = float(input("Digite o coeficiente a: "))
b = float(input("Digite o coeficiente b: "))
c = float(input("Digite o coeficiente c: "))

raizes = calcular_raizes(a, b, c)

if len(raizes) == 2:
    print(f"As raízes da equação são {raizes[0]} e {raizes[1]}")
else:
    print(f"A Raiz da equação é: {raizes[0]}")