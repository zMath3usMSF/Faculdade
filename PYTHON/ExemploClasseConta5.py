import datetime
from ExemploClasseExtrato import Extrato

class Conta:
    def __init__(self, clientes, numero, saldo):
        self.clientes = clientes
        self.numero = numero
        self.saldo = saldo
        self.data_abertura = datetime.datetime.today()
        self.extrato = Extrato()

    def depositar(self, valor):
        self.saldo += valor
        self.extrato.transacoes.append(["DEPÓSITO", valor, datetime.datetime.now()])

    def sacar(self, valor):
        if self.saldo < valor:
            print(f"Não existe saldo suficiente conta numero {self.numero}")
            return False
        else:
            self.saldo -= valor
            self.extrato.transacoes.append(["SAQUE", valor, datetime.datetime.now()])
            return True
        
    def transfereValor(self, contaDestino, valor):
        if self.saldo < valor:
            return ("Saldo insuficiente.")
        else:
            contaDestino.depositar(valor)
            self.saldo -= valor
            self.extrato.transacoes.append(["TRANSFERÊNCIA", valor, datetime.datetime.now()])
            return("Transferência realizada.")
        
    def gerarSaldo(self):
        print(f"Conta Número: {self.numero}")
        print(f"Saldo: R$ {self.saldo:10.2f}")