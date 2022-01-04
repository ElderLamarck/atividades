nome_nota = dict()
ficha_notas = list()
nomes_alunos = list()
media_notas_lista = 0
controlador = 0
controlador_modulo = 0
peso_nota = 0.7
peso_lista = 0.3

numero_modulos = int(input())
numero_alunos = int(input())

while controlador != numero_alunos:
    nomes_alunos.append(input())
    controlador += 1
controlador = 0

while controlador_modulo != numero_modulos:
    numero_ficha = int(input())
    nota = float(input())

    while controlador != (numero_ficha * numero_alunos) + numero_alunos:
        for i in range(numero_ficha):
            ficha_notas.append(input())
            controlador += 1
            for value in ficha_notas:
                media_notas_lista = float(value) + media_notas_lista
            for parts in nomes_alunos:
                nome_nota[parts] = nota + media_notas_lista

    controlador_modulo += 1
controlador = 0

media_notas_lista = media_notas_lista / numero_ficha
nota_final = (peso_lista * media_notas_lista) + (peso_nota * nota)

print(f'{nota_final:.2f}')

if 0 <= nota_final < 3:
    print('REPROVADO')
elif 3 <= nota_final < 5:
    print('TA DIFICIL')
elif 5 <= nota_final < 7:
    print('FOI POR POUCO')
elif 7 <= nota_final < 9:
    print('PASSOU')
elif nota_final >= 9:
    print('PASSOU FACIL')
