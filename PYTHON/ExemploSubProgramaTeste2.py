def func1(x):
    x = 10
    print(f"Função func1 - x = {x}")
    return x

def func2(x):
    x = 20
    print(f"Função func2 - x = {x}")
    return x

vn = 0
print(f"Programa principal - vn = {vn}")
vn = func1(vn)
print(f"Programa principal - vn = {vn}")
vn = func2(vn)
print(f"Programa principal - x = {vn}")