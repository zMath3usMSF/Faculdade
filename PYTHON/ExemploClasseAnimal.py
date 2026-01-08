class Animal:
    def __init__(self, nome):
        self.nome = nome
    
    def falar(self):
        pass

    def mover(self):
        pass

class Cachorro(Animal):
    def falar(self):
        return "Au!"

    def mover(self):
        return f"{self.nome} está andando."
    
class Gato(Animal):
    def falar(self):
        return "Miau!"
    
    def mover(self):
        return f"{self.nome} está andando."
    
class Vaca(Animal):
    def falar(self):
        return "Muu!"
    
    def mover(self):
        return f"{self.nome} está andando."
    
class Voador:
    def voar(self):
        return f"{self.nome} está voando."
    
class Nadador:
    def nadar(self):
        return f"{self.nome} está nadando."
    
class Pato(Animal, Voador, Nadador):
    def falar(self):
        return "Quack!"
    
    def mover(self):
        return f"{self.andar()} {self.nadar()} {self.voar()}"
    
    def andar(self):
        return f"{self.nome} está andando."

def fazer_som(animal):
    return animal.falar()

def fazer_movimento(animal):
    return animal.mover()

cachorro = Cachorro('Lug')
gato = Gato('Floquinho')
vaca = Vaca('Mimosa')
pato = Pato("Pato Donald")

print(fazer_som(cachorro))
print(fazer_som(gato))
print(fazer_som(vaca))
print(fazer_som(pato))

print(fazer_movimento(cachorro))
print(fazer_movimento(gato))
print(fazer_movimento(vaca))
print(fazer_movimento(pato))