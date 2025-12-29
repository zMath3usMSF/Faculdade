print("Antes WHILE")
palavra = input("Entre com uma palavra: ").lower()
while palavra != "sair":
    print("Dentro WHILE")
    palavra = input("Digite sair para encerrar o WHILE:")
print("Você digitou para sair e agora está fora do WHILE.")

while True:
    print('Você está no primeiro laço.')
    opcao1 = input("Deseja sair dele? Digite SIM para isso. \n").upper()
    if opcao1 == "SIM":
        break
    else:
        while True:
            print("Você está no segundo WHILE.")
            opcao2 = input("Deseja sair dele? Digite SIM para isso. \n").upper()
            if opcao2 == "SIM":
                break
        print("VoC~e saiu do segundo laço.")
print("Você saiu do primeiro laço.")