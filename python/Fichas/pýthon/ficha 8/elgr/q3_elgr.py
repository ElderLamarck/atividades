prohibited = input().upper().split()
prohibited_words = dict()
for word in prohibited:
    prohibited_words[word] = 0

phrase = input().upper().split('.')
phrase = ''.join(phrase)
phrase = phrase.split(',')
phrase = ''.join(phrase)
phrase = phrase.split()

while phrase != ['FIM']:
    for words in phrase:
        if prohibited_words.get(words, -1) != -1:
            prohibited_words[words] = int(prohibited_words[words]) + 1

    phrase = input().upper().split('.')
    phrase = ''.join(phrase)
    phrase = phrase.split(',')
    phrase = ''.join(phrase)
    phrase = phrase.split()

prohibited_words = sorted (prohibited_words.items())
for key, value in prohibited_words:
    if value != 0:
        print(f'{key} {value}')
