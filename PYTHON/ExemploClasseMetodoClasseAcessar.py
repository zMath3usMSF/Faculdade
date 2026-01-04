from ExemploClasseMetodoClasse import ClasseMetodoClasse

classe = ClasseMetodoClasse(0)

# Como o Contador da Classe é privado, não é possível acessar ele
# Se tentar, dará erro
# print(classe.contador)

# Podemos criar Metódos da Classe para Acessar Atributos da Classe Privados
print(classe.obterContador())