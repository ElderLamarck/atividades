nota = float(input())
numero_listas = int(input())
listas_notas = list()
media_notas_lista = 0
controlador = 0
peso_nota = 0.7
peso_lista = 0.3


while controlador != numero_listas:
    listas_notas.append(input())
    controlador += 1

for value in listas_notas:
    media_notas_lista = float(value) + media_notas_lista

media_notas_lista = media_notas_lista / numero_listas
nota_final = (peso_lista * media_notas_lista) + (peso_nota * nota)
print(f'{nota_final:.2f}')

if 0 <= nota_final < 3:
    print('RED ZONE!')
elif 3 <= nota_final < 5:
    print('DA PRA RECUPERAR!')
elif 5 <= nota_final < 7:
    print('QUASE LA!')
elif 7 <= nota_final < 9:
    print('TA FAVORAVEL!')
elif nota_final >= 9:
    print('EXECELENTE!')
