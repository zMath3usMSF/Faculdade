# Criando um dicionário com alguns pares chave-valor
dicionario = {
    "nome" : "Alice",
    "idade" : 25,
    "cidade" : "São Paulo"
}

# Acessando e imprimindo valores individuais usanod chaves
nome = dicionario["nome"]
idade = dicionario["idade"]
cidade = dicionario["cidade"]

print(f"Nome: {nome}")
print(f"Idade: {idade}")
print(f"Cidade: {cidade}")

# Adicionando um novo par chave-valor ao dicionário
dicionario["profissão"] = "Engenheira"
print(f"Dicionário após adicionar profissão: {dicionario}")

# Modificando o valor associado a uma chave existente
dicionario["idade"] = 26
print(f"Dicionário após modificar a idade: {dicionario}")

# Removendo um par chave-valor ao dicionário
del dicionario["cidade"]
print(f"Dicionário após remover a cidade: {dicionario}")

# Acessando todas as chaves e valores do dicionário
chaves = dicionario.keys()
valores = dicionario.values()

print(f"Chaves: {list(chaves)}")
print(f"Valores: {list(valores)}")

# Iterando sobre os pares chave-valor do dicionário
print("Iterando sobre o dicionário:")
for chave, valor in dicionario.items():
    print(f"{chave}: {valor}")

# Verificando se uma chave existe no dicionário
if "nome" in dicionario:
    print(f'O nome no dicionário é: {dicionario["nome"]}')
else:
    print(f'A chave "nome" não está no dicionário')

# Usando o método get() para acessar valores de forma segura
profissao = dicionario.get("profissão", "Desconhecido")
print(f"Profissão: {profissao}")

# Limpando todos os elementos do dicionário
dicionario.clear()
print(f"Dicionário após limpar todos os elementos: {dicionario}")