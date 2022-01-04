MESA1 = ['FLAMENGO', 'SPORT', 'VITORIA']
MESA2 = ['VASCO', 'TREZE', 'SANTOS']
MESA3 = ['BAHIA', 'FORTALEZA', 'GREMIO']
mesa1 = list()
mesa2 = list()
mesa3 = list()
mesa4 = list()
dados = ''

contador = 0
contadorpessoas = 1


while contador < 10 and dados != '-1':
    dados = input()
    if dados != '-1':
        dados = dados.upper().split()
        nome = dados[0]
        idade = int(dados[1])
        time = dados[2]

        if time in MESA1 and idade >= 30:
            mesa1.append(nome)

        elif time in MESA2 and idade >= 18 and idade <= 36:
            mesa2.append(nome)

        elif time in MESA3 and idade >= 10 and idade <= 18:
            mesa3.append(nome)

        else:
            mesa4.append(nome)

        contador += 1

if contador == 0:
    print('JANTAR SEM CONVIDADOS')

else:
    print()
    print('MESA 1')
    if len(mesa1) == 0:
        print('VAZIA')
    else:   
        contadorpessoas = 1   
        for i in mesa1:
            print(str(contadorpessoas) + ' ' + i)
            contadorpessoas += 1
    print()
    print('MESA 2')
    if len(mesa2) == 0:
        print('VAZIA')
    else:
        contadorpessoas = 1           
        for i in mesa2:
            print(str(contadorpessoas) + ' ' + i)
            contadorpessoas += 1
    print()
    print('MESA 3')
    if len(mesa3) == 0:
        print('VAZIA')
    else:
        contadorpessoas = 1                   
        for i in mesa3:
            print(str(contadorpessoas) + ' ' + i)
            contadorpessoas += 1
    print()
    print('MESA 4')
    if len(mesa4) == 0:
        print('VAZIA')
    else:
        contadorpessoas = 1               
        for i in mesa4:
            print(str(contadorpessoas) + ' ' + i)
            contadorpessoas += 1