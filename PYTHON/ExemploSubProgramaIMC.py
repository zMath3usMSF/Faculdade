def calcula_imc (peso, altura):
    return peso * 100 / (altura * 2)

peso = eval(input("Digite o peso em quilos: "))
altura = eval(input("Digite a altura em centimentros: "))
imc = calcula_imc(peso, altura)
print("imc = ", imc)