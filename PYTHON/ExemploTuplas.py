# Tupla

tupla_heterogenea = (1, "Olá", 3.14, [10, 20, 30], {"chave": "valor"})

# Acessando e imprimindo elementos individuais da tupla
print(f"Inteiro: {tupla_heterogenea[0]}")
print(f"String: {tupla_heterogenea[1]}")
print(f"Float: {tupla_heterogenea[2]}")
print(f"Lista: {tupla_heterogenea[3]}")
print(f"Dicionário: {tupla_heterogenea[4]}")

# Modificando a lista dentro da tupla
tupla_heterogenea[3].append(40)
print(f"Lista modificada: {tupla_heterogenea[3]}")

# Acessando um valor no dicionário dentro da dupla
valor_dict = tupla_heterogenea[4]["chave"]
print(f"Valor no dicionário: {valor_dict}")

# Iterando sobre a tupla e imprimindo os tipos de cada elemento
for elemento in tupla_heterogenea:
    print(f"Elemento: {elemento}, Tipo: {type(elemento)}")