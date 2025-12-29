def soma_numeros(a, b):
    try:
        resultado = a + b
        return resultado
    except TypeError:
        return "Erro: entrada inválida"
    except Exception as e:
        return f"Erro inesperado: {e}"

# Testes da função com números válidos
print(soma_numeros(2, 3)) 
# Saída: 5 

# Testes da função com números inválidos
print(soma_numeros("a", 3))
# Saída: Erro: entrada inválida

# Testes da função com outros tipos de dados
print(soma_numeros(True, 3))
# Saída: 4 (pois True é considerado 1 em Python)

# Testes da função com uma lista
print(soma_numeros([1, 2], 3))
# Saída: Erro: entrada inválida