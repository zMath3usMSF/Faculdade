from ExemploClasseAtributosPrivados import ClasseAtributosPrivados

classe = ClasseAtributosPrivados(10, 20)
# Em Python não existe realmente Atributos Privados, o que acontece é que devemos indicar ao programador
# que aquele Atributo é Privado pelo seu nome, adicionando _ (privado) ou __ (fortemente privado)

# Ao tentar acessar o valor irá dar erro, pois o nome do atributo é diferente
# print(classe.valor1)
# print(classe.valor2)

# Porém, é possível burlar
# Caso for _
print(classe._valor1)

# Caso for __
print(classe._ClasseAtributosPrivados__valor2)

# Mas fazer isso não faz sentido, pois o objetivo de usar underline na frente é para justamente
# impedir dos Atributos não serem acessados, e isso é considerado uma má prática de programação
# Se quer acessar os valores por fora, é só não declarar como privado!