class Conta:
    def __init__(self, numero, cpf, nomeTitular, saldo):
        self.numero = numero
        self.cpf = cpf
        self.nomeTitular = nomeTitular
        self.saldo = saldo
    
    def depositar(self, valor):
        self.saldo += valor

    def sacar(self, valor):
        if self.saldo < valor:
            return False
        else:
            self.saldo -= valor
            return True
    
    def gerar_extrato(self):
        print(f"numero: {self.numero} \ncpf: {self.cpf} \nsaldo: {self.saldo}")

def main():
    c1 = Conta(432, "123.456.789-10", "João", 1000)
    c1.depositar(300)
    c1.gerar_extrato()
    c1.sacar(25)
    c1.gerar_extrato()

main()