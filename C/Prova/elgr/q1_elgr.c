#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main(void)
{
	int linha;
	int coluna;
	int value;
	int i;
	int matriz[3][3];
	int lista[9];

	while (scanf(" %d", &value) != EOF) {
		lista[i] = value;
		i++;
		if (i != 9) {
			continue;
		} else {
			for (linha = 0; linha != 3; linha++) {
				for (coluna = 0; coluna != 3; coluna++) {
					matriz[linha][coluna] =
						lista[(3 * linha) + coluna];
				}
			}

			if (matriz[0][1] == 0 && matriz[0][2] == 0 &&
			    matriz[1][2] == 0) {
				printf("Por cima\n");
			}

			else if (matriz[2][0] == 0 && matriz[2][1] == 0 &&
				 matriz[1][0] == 0) {
				printf("Por baixo\n");
			} else {
				printf("Nao pode atravessar\n");
			}
			i = 0;
		}
	}
	return 0;
}