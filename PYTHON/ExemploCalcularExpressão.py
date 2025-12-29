def calcular_expressao():
    # Solicitar ao usuário que insira uma expressão matemática
    expressao = input("Digite uma expressão matemática: ")

    try:
        # Avaliar a expressão usando eval
        resultado = eval(expressao)
        print("O resultado da expressão é:", resultado)
    except Exception as e:
        print("Erro ao avaliar a expressão:", e)
    
# Chamar a função
calcular_expressao()
# Exemplo da chamada do programa:
# Digite uma expressão matemática: 2 + 3 * (4 - 1)
# O resultado da expressão é: 11