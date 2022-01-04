ARROZ = 5.50
FEIJAO = 6.00
OLEO = 7.50
SAL = 1.99
ACUCAR = 4.00
CAFE = 6.70
MOLHO_TOMATE = 1.20
MACARRAO = 2.80
FARINHA_TRIGO = 5.30
PAO = 5.00
MANTEIGA = 3.00
BANANA = 2.00
LEITE = 3.50
SABONETE = 0.80
CREME_DENTAL = 1.00
ESCOVA_DENTES = 0.80
DESODORANTE = 5.40
ABSORVENTE = 1.90
SHAMPOO = 5.00
PAPEL_HIGIENICO = 10.00
DETERGENTE_LIQUIDO = 0.50
SABAO_BARRA = 0.50
SABAO_PO = 5.00
AMACIANTE = 4.50
AGUA_SANITARIA = 1.99
MULTIUSO = 2.90
ESPONJA_ACO = 0.30

list_cesta = (ARROZ, FEIJAO, OLEO, SAL, ACUCAR, CAFE, MOLHO_TOMATE, MACARRAO, FARINHA_TRIGO, PAO, MANTEIGA,
BANANA, LEITE, SABONETE, CREME_DENTAL, ESCOVA_DENTES, DESODORANTE, ABSORVENTE, SHAMPOO, PAPEL_HIGIENICO,
DETERGENTE_LIQUIDO, SABAO_BARRA, SABAO_PO, AMACIANTE, AGUA_SANITARIA, MULTIUSO, ESPONJA_ACO)

valor = 1
preco_total = 0
num_cestas = 0

dados = input().split(',')
doacao = float(input())

while valor <= 27:
    preco_total = (float(dados[valor - 1]) * list_cesta[valor - 1]) + preco_total
    valor += 1

num_cestas = doacao // preco_total

print(f'O valor da cesta básica ficou em: R${preco_total:.2f}')
print(f'Com o valor doado pode ser comprada {int(num_cestas)} cestas básicas')