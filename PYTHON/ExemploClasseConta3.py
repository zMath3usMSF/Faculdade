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
    
    def transferir(self, contaDestino, valor):
        if(self.saldo > valor):
            self.saldo -= valor
            contaDestino.saldo += valor
        else:
            print("Saldo insuficiente.")

    def gerar_extrato(self):
        print(f"numero: {self.numero} \ncpf: {self.cpf} \nsaldo: {self.saldo}")

def main():
    conta1 = Conta(432, "123.456.789-10", "João", 1000)
    conta2 = Conta(210, "123.456.789-11", "Maria", 500)
    conta1.transferir(conta2, 250)
    conta1.gerar_extrato()
    conta2.gerar_extrato()

main()