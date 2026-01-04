from ExemploClasseAtributosClasse import ClasseAtributosClasse

# Criando Instâncias e Verificando o Contador
classe1 = ClasseAtributosClasse(10)
print(f"Valor do Valor1 da Classe1 {classe1.valor1}")
print(f"Valor do Contador da Classe1: {classe1.contador}")

classe2 = ClasseAtributosClasse(3)
print(f"Valor do Valor1 da Classe2 {classe2.valor1}")
print(f"Valor do Contador da Classe2: {classe2.contador}")

classe3 = ClasseAtributosClasse(24)
print(f"Valor do Valor1 da Classe3 {classe3.valor1}")
print(f"Valor do Contador da Classe3: {classe3.contador}")

# Note que o valor do Contador foi aumentando, conforme criavamos novas instâncias
# Se verificarmos todas as Instâncias tem o mesmo valor do Contador
print(f"Valor do Contador da Classe1: {classe1.contador}")
print(f"Valor do Contador da Classe2: {classe2.contador}")
print(f"Valor do Contador da Classe3: {classe3.contador}")

# Isso acontece porque o Contador não faz parte da Instância e sim da Classe
# Podemos até acessar ele diretamente sem a necessidade de passar pela Instância
# Porque ele não faz parte dela
print(f"Valor do Contador: {ClasseAtributosClasse.contador}")