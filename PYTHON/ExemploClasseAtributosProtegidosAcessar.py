from ExemploClasseAtributosProtegidos import ClasseAtributosProtegidos

classe = ClasseAtributosProtegidos(0)

# Obtendo o valor do Atributo Protegido
print(classe.valor1)

# Definindo um valor ao Atributo Protegido
classe.valor1 = 10

# Obtendo o valor atualizado do Atributo Protegido
print(classe.valor1)