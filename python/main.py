numero = int(input())
divisao_4 = numero % 4
divisao_5 = numero % 5
divisao_7 = numero % 7

if divisao_5 == 0:
    print('nao')
elif divisao_4 == 0:
    if divisao_7 == 0:
        print('sim')
    else:
        print('nao')
else:
    print('nao')
