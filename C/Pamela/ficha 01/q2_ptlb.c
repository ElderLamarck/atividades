#include <stdlib.h>
#include <stdio.h>
#include <string.h>

struct dadosClientes {
	int conta;
	char nome[69];
	char sobrenome[69];
	float saldo;
	struct dadosClientes *next;
};

struct dadosClientes *head = NULL;

int clientesLista(void)
{
	FILE *clientes = fopen("CLIENTES.txt", "r");

	int conta;
	char nome[69];
	char sobrenome[69];
	float saldo;

	while (fscanf(clientes, " %d %s %s %f", &conta, nome, sobrenome, &saldo) != EOF) {
		struct dadosClientes *cliente = malloc(sizeof(struct dadosClientes));

		cliente->conta = conta;
		cliente->saldo = saldo;
		strcpy(cliente->nome, nome);
		strcpy(cliente->sobrenome, sobrenome);

		cliente->next = head;
		head = cliente;

		cliente = cliente->next;
	}
	fclose(clientes);
	return 0;
}

int transacoes(void)
{
	FILE *transactions = fopen("TRANSACTIONS.txt", "r");

	int conta;
	float valorTransacao;
	char transacao;

	while (fscanf(transactions, " %d %c %f", &conta, &transacao, &valorTransacao) != EOF) {
		struct dadosClientes *cliente = head;

		while (cliente != NULL) {
			if (cliente->conta == conta) {
				if (transacao == '-') {
					cliente->saldo -= valorTransacao;
				} else {
					cliente->saldo += valorTransacao;
				}
			}
			cliente = cliente->next;
		}
	}
	fclose(transactions);
	return 0;
}

int devedores(void)
{
	FILE *devedor = fopen("DEVEDORES.txt", "w");

	struct dadosClientes *cliente = head;

	while (cliente != NULL) {
		if (cliente->saldo < 0) {
			fprintf(devedor, "%d %s %s %.2f\n", cliente->conta, cliente->nome, cliente->sobrenome, cliente->saldo);
		}
		cliente = cliente->next;
	}
	fclose(devedor);
	return 0;
}

int main(void)
{
	clientesLista();
	transacoes();
	devedores();
	return 0;
}