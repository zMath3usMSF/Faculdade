class Conta:
    def __init__(self, clientes, numero, saldo):
        self.clientes = clientes
        self.numero = numero
        self.saldo = saldo

    def depositar(self, valor):
        self.saldo += valor

    def sacar(self, valor):
        if self.saldo < valor:
            return False
        else:
            self.saldo -= valor
            return True
        
    def transfereValor(self, contaDestino, valor):
        if self.saldo < valor:
            return ("Saldo insuficiente.")
        else:
            contaDestino.depositar(valor)
            self.saldo -= valor
            return("Transferência realizada.")
        
    def gerarSaldo(self):
        print(f"Conta Número: {self.numero} | Saldo: {self.saldo}")