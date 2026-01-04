class ClasseMetodoClasse:
    _contador = 0

    def __init__(self, valor1):
        self.valor1 = valor1
        type(self)._contador += 1

    # Criando um Metódo da Classe
    @classmethod
    def obterContador(cls):
        return cls._contador