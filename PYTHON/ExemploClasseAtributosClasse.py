class ClasseAtributosClasse:
    # Atributo da Classe
    contador = 0

    def __init__(self, valor1):
        self.valor1 = valor1
        # Aumentando o valor do Contador da Classe toda vez que uma nova Instância da Classe é criada
        ClasseAtributosClasse.contador += 1