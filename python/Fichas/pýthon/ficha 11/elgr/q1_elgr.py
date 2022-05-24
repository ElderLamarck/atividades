def leds(coluna, cor):
    valores = list()
    coluna = int(coluna)
    for linhasM in matriz:
        valores.append(linhasM[coluna-1])
    if cor == 'R':
        for i in valores:
            print(i)
    if cor == 'G':
        for i in valores:
            i = int(i)
            if (i % 2) == 0:
                print(i)
    if cor == 'B':    
        for i in valores:
            i = int(i)
            if (i % 2) != 0:
                print(i)

matriz = list() 
linha = list()
contador = 0

info = input().split()
n_colunas = int(info[0])
n_linhas = int(info[1])

while len(matriz) != n_linhas: 
    contador += 1 
    linha.append(contador) 

    if len(linha) == n_colunas: 
        matriz.append(linha) 
        linha = list() 

coluna1 = input()
cor1 = input()

coluna2 = input()
cor2 = input()

coluna3 = input()
cor3 = input()

leds(coluna1,cor1)
print()
leds(coluna2,cor2)
print()
leds(coluna3,cor3)