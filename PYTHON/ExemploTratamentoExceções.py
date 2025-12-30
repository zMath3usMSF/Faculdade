while True:
    try:
        nr = int(input('digite um número:'))
        s = nr * 3
        print(s)
        q = 12 /s
        print(q)
    except ValueError:
        print('Entre com um número válido')
    except ZeroDivisionError:
        print('O número não pode ser zero')
    else:
        print('entrou no else')
        break
    finally:
        print('entrou no finally')