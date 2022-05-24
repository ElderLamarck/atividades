key = int(input())
counter = 0
index = 0
letters_count_list = list()
letters_in_phrase = list()
phrase = list()
letters_final = list()

while counter != key:
    phrase.append(input())
    counter += 1

phrase = ' '.join(phrase)
letters_count = input()

for letters in letters_count:
    letters_count_list.append(letters)


while index != len(letters_count_list):
    for letters in phrase:
        if letters == letters_count_list[index]:
            letters_in_phrase.append(letters_count_list[index])

    counter = letters_in_phrase.count(letters_count_list[index])

    letters_final.append(counter)
    index += 1

index = 0

while index != len(letters_final):
    print(letters_count_list[index], '=', letters_final[index])
    index += 1
