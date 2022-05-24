dna = input().upper()
base = input()
index = 0
base_counter = 0
higher_base = 0
higher_base_2 = 0
higher_index = 0

if dna.find(base) != -1:
    for letter in dna:
        if letter == base:
            base_counter = base_counter + 1

            if base_counter > higher_base:
                higher_base_2 = higher_base
                higher_base = base_counter

                if higher_base != higher_base_2:
                    higher_index = index - higher_base_2

        else: base_counter = 0
        index += 1

    print(higher_index)
    print(higher_base)

else: print('ERRO')