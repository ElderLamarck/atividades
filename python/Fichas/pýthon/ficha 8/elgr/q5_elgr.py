nome_media = dict()
contador_nome = dict()
contador = 0

info = input().split()

odometro_anterior = int(info[0])
volume = float(info[1])
nome_anterior = info[2]

while info != ['FIM']:

    odometro = int(info[0])
    volume = float(info[1])
    nome = info[2]

    if nome_media.get(nome, 0) != 0:
        somatorio = nome_media.get(nome_anterior, 0)
        nome_media[nome_anterior] = ((odometro - odometro_anterior)/volume) + somatorio

        contador_nome[nome_anterior] = int(contador_nome[nome_anterior]) + 1

    else:
        nome_media[nome_anterior] = ((odometro - odometro_anterior) / volume)
        contador_nome[nome] = 1

    odometro_anterior = odometro
    nome_anterior = nome
    info = input().split()

for nome in nome_media:
    somatorio = nome_media[nome]
    nome_media[nome] = f'{somatorio / contador_nome[nome_anterior]:.2f}'

nome_media_ordenado = sorted(nome_media.items())
for nome in nome_media_ordenado:
    print(f'{nome[0]}: {nome[1]}')
