class ExcecaoCustomizada(Exception):
    pass

def checa_valor(valor):
    if valor < 0:
        raise ExcecaoCustomizada("Valor não pode ser negativo!")
    
def divide(a, b):
    return a / b