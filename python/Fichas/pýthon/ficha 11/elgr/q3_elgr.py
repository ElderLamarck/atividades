pessoa_1 = input()
pessoa_2 = input()
pessoa_3 = input()
pessoa_4 = input()
pessoa_5 = input()
troca = ''

# p4 p2  
#       p1
# p5 p3

#O Mário deve está na posição 2 ou posição 3, dependendo da posição em que ele chegou.
#O Toad deve sentar proximo da posiçâo 1 porém, se o Mário estiver no mesmo lado que ele, o Mário é quem sentará mais perto da princesa.
#Se o Luigi e o Yoshi estiverem no mesmo lado, o Luigi deve sentar mais próximo da princesa.
#As pessoas que chegaram em posições pares tem de sentar em posições pares na mesa.

lugar1 = pessoa_1
lugar2 = pessoa_2
lugar3 = pessoa_3
lugar4 = pessoa_4
lugar5 = pessoa_5

if pessoa_4 == 'Mario':
    troca = lugar2
    lugar2 = 'Mario'
    lugar4 = troca

elif pessoa_5 == 'Mario':
    troca = lugar3
    lugar3 = 'Mario'
    lugar5 = troca


if lugar2 != 'Mario' and lugar2 != 'Toad' and pessoa_3 != 'Toad' and pessoa_5 != 'Toad':
    
    troca = lugar2
    lugar2 = 'Toad'
    if lugar3 == 'Toad':
        lugar3 = troca
    if lugar4 == 'Toad':
        lugar4 = troca
    if lugar5 == 'Toad':
        lugar5 = troca

elif lugar3 != 'Mario' and lugar3 != 'Toad'and  pessoa_2 != 'Toad' and pessoa_4 != 'Toad':
    troca = lugar3
    lugar3 = 'Toad'
    if lugar2 == 'Toad':
        lugar2 = troca
    if lugar4 == 'Toad':
        lugar4 = troca
    if lugar5 == 'Toad':
        lugar5 = troca

if lugar2 == 'Yoshi':
    if lugar4 == 'Luigi':
        lugar2 = 'Luigi'
        lugar4 = 'Yoshi'

if lugar3 == 'Yoshi':
    if lugar5 == 'Luigi':
        lugar3 = 'Luigi'
        lugar5 = 'Yoshi'

print('\n{}\n{}\n{}\n{}\n{}\n'.format(lugar1,lugar2,lugar3,lugar4,lugar5))