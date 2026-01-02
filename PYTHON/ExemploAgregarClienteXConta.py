from ExemploClasseConta4 import Conta
from ExemploClasseCliente import Cliente

cliente1 = Cliente(123, "João", "Rua 1")
cliente2 = Cliente(345, "Maria", "Rua 2")

conta1 = Conta([cliente1, cliente2], 1, 0)

conta1.gerarSaldo()
conta1.depositar(1500)
conta1.sacar(500)
conta1.gerarSaldo()