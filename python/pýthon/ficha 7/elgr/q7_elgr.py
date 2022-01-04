phrase_old = input()
index = 0

while phrase_old != '*':
    phrase_list = phrase_old.title().split()
    for word in phrase_list:
        if word == 'Da':
            phrase_list[index] = phrase_list[index].lower()
        if word == 'De':
            phrase_list[index] = phrase_list[index].lower()
        if word == 'Di':
            phrase_list[index] = phrase_list[index].lower()
        if word == 'Do':
            phrase_list[index] = phrase_list[index].lower()
        if word == 'Du':
            phrase_list[index] = phrase_list[index].lower()
        if word == 'E':
            phrase_list[index] = phrase_list[index].lower()
        index += 1

    index = 0
    phrase_new = ' '.join(phrase_list)
    print(phrase_new)
    phrase_old = input()
