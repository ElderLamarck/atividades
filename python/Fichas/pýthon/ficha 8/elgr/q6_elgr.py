produto_nome_preco = dict()
info_produto = input().split()
total = 0

while info_produto != ['*']:

    preco = info_produto.pop(-1)
    nome = ' '.join(info_produto)
    produto_nome_preco[nome] = preco

    info_produto = input().split()

comando = input()
while comando != 'total':
    comando = comando.split()

    if comando[0] == 'quantidade':
        print(len(produto_nome_preco))

    elif comando[0] == 'retire':
        comando_retirado = comando.pop(0)
        comando = ' '.join(comando)

        produto_nome_preco.pop(comando, 0)
    comando = input()

for valores in produto_nome_preco:
    valores = produto_nome_preco.get(valores)
    total = float(valores) + total
print(f'{total:.2f}')

