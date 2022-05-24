word = 'null'
new_word = 'null'

while True:

    word = input()
    new_word = word.replace('3', 'E')
    new_word = new_word.replace('1', 'I')
    new_word = new_word.replace('4', 'A')
    new_word = new_word.replace('5', 'S')

    if (new_word.upper() != 'SAIR') and (new_word.upper() != 'FIM'):
        print(new_word.upper())

    else: break

