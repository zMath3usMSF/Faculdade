from datetime import date

class Pessoa:
    def __init__(self, nome, idade):
        self.nome = nome
        self.idade = idade
    
    @classmethod
    def ApartirAnoNasc(cls, nome, ano):
        return cls(nome, date.today().year - ano)
    
    @staticmethod
    def EhMaior(idade):
        return idade >= 18
    
pessoa1 = Pessoa('Ventury', 62)
print(pessoa1.nome)
print(pessoa1.idade)
print(Pessoa.EhMaior(pessoa1.idade))
pessoa2 = Pessoa.ApartirAnoNasc('LUG', 2013)
print(pessoa2.nome)
print(pessoa2.idade)
print(Pessoa.EhMaior(pessoa2.idade))