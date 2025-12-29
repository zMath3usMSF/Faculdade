for raiz in range (32,100):
    num = raiz * raiz # Calcula o número gerado pela raiz
    menor = num % 100 # Obtém o número dos algarismos menos significativos
    maior = num // 100 # Obtém o número dos algarismos mais significativos

    if (menor + maior) == raiz: # Valida se a raiz corresponde a soma
        print(num)
        print(menor)
        print(maior)
        print(raiz)
        print("")
print("Terminou")
print("Saiu ", raiz)