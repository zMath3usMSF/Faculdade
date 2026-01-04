class ClasseAtributosProtegidos:
    def __init__(self, valor1):
        self._valor1 = valor1
    
    # Para definir um atributo como protegido, devemos usar o @property
    # Com isso só iremos poder acessar ele por este metódo
    @property
    def valor1(self):
        return self._valor1

    # Se quiser definir um valor, devemos usar o @nome_do_atributo.setter
    # Com isso o método definido como setter será chamado
    # Exemplo de uso nome_do_atributo = 10
    @valor1.setter
    def valor1(self, valor):
        self._valor1 = valor + 99 # Podemos fazer modificações na hora de definir o valor