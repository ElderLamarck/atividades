BRUXO = 'B'
ANAO = 'A'
ELFO = 'E'
HUMANO = 'H'
DIA = 'D'
NOITE = 'N'
CHUVA = 'c'
SOL = 's'
NEVE = 'n'
chance = None

info = input()
info = info.split()


raça = info[0]           # É um caractere indicando a sua raça
horario = info[1]        # É um caractere indicando o horário atual 
tempo = info[2]          # É um caractere que indica a condição de tempo atual
altura = float(info[3])  # É um double indicando a sua altura em metros
luta = float(info[4])    # É um double indicando a sua capacidade de luta
stealth = float(info[5]) # É um double indicando a sua capacidade de stealth

if raça == HUMANO:
    raça = 'humano'
    chance = 100

if raça == ANAO:
    raça = 'anao'
    if altura < 1.50:
        stealth = stealth + 2

    elif altura > 1.80:
        stealth = stealth - 5

elif raça == BRUXO:
    raça = 'bruxo'
    if horario == NOITE:
        
        if altura < 1.70: 
            stealth = stealth + 3

        elif altura > 2.00:
            stealth = stealth - 4

        if tempo == SOL:
            stealth = stealth - 1

        elif tempo == NEVE:
            chance = 100

        elif tempo == CHUVA:
            luta = luta + 3
            stealth = stealth + 3

    else:
         chance = 0

    
elif raça == ELFO:
    raça = 'elfo'
    if horario == DIA:
        if altura < 1.60:
            stealth = stealth + 1

        elif altura > 1.90:
            stealth = stealth - 6

        if tempo == CHUVA:
            luta = luta - 2

        elif tempo == SOL:
            stealth = stealth - 1
        
        elif tempo == NEVE:
            chance = 0
    else:
        chance = 0

if chance is None:
    chance = 10*((luta + stealth)/2)

    if chance > 100:
        chance = 100

    if chance < 0:
        chance = 0

print(f'A taxa de sucesso do {raça} para entrar em Novigrad e de {chance:.2f}%')