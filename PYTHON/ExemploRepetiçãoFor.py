nome = input('Entre com um nome: ')
for letra in nome:
    print(letra)

nomes = ['Laura', 'Lis', 'Guilherme', 'Enzo', 'Arthur']
for nome in nomes:
    print(nome)

numeros = [1, 2, 3, 4, 5]
for numero in numeros:
    quadrado = numero ** 2
    print(f'O quadrado de {numero} é {quadrado}')

soma = 0
for numero in numeros:
    soma += numero
print(f'A soma de todos os números é {soma}')

texto = "programação"
letra_para_contar = "r"
contador = 0
for letra in texto:
    if letra == letra_para_contar:
        contador +=1
print(f"A letra '{letra_para_contar}' aparece {contador} vezes na palavra '{texto}")