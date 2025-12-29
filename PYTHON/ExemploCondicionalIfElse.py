vnr = eval(input('Digite um número: '))
print('Número digitado: ',vnr)
print('Antes do IF')
if vnr <= 100:
    print('Entrou no IF do 100')
elif vnr <= 500:
    print('Entrou no ELIF do 500')
elif vnr <= 1000:
    print('Entrou no ELIF do 1000')
else:
    print('Entrou no ELSE')
print('Saiu do IF')