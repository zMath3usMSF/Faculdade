import numpy as np # pip install numpy

def calcular_raizes(a, b, c):
    coeficientes = [a, b, c]

    raizes = np.roots(coeficientes)
    return raizes

a = float(input("Digite o coeficiente a: "))
b = float(input("Digite o coeficiente b: "))
c = float(input("Digite o coeficiente c: "))

raizes = calcular_raizes(a, b, c)

print(f"As raízes da equação são: {raizes[0]} e {raizes[1]}")