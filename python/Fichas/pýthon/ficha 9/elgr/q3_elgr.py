palavras_proibidas_list = list()
palavras_proibidas_numero = int(input())
palavras_proibidas_dict = dict()
palavras_proibidas_final = dict()
controlador = 0
teste_threshold = 0.0

while controlador != palavras_proibidas_numero:
    palavras = input().upper().split()
    palavras_proibidas_list.append(palavras)
    controlador += 1

for partes in palavras_proibidas_list:
    palavras_proibidas_dict[partes[0].upper()]= 0

threshold = float(input())

frase = input().upper().split('.')
frase = ''.join(frase)
frase = frase.split(',')
frase = ''.join(frase)
frase = frase.split()

for partes in frase:
    if palavras_proibidas_dict.get(partes, -1) != -1:
            palavras_proibidas_dict[partes] = (int(palavras_proibidas_dict[partes]) + 1)


for partes in palavras_proibidas_list:
    palavras_proibidas_final[partes[0].upper()] = float(partes[1]) * palavras_proibidas_dict.get(partes[0], 0)

palavras_proibidas_dict = sorted(palavras_proibidas_dict.items())
for key, value in palavras_proibidas_dict:
    if value != 0:
        print(f'{key} {value}')

for valores in palavras_proibidas_final:
    valores = palavras_proibidas_final.get(valores)
    teste_threshold = float(valores) + teste_threshold

if teste_threshold > threshold:
    print('SIM')

else: print('N�O')
