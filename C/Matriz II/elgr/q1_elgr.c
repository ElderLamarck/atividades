#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {
    int coluna, linha, voto = 0;
    int princesa;
    int eleitores;
    scanf("%d", &princesa);    //colunas
    scanf(" %d", &eleitores); //linhas

    int matrizVoto[eleitores][princesa];
    
    for (linha=0; linha != eleitores; linha++){
        for (coluna=0; coluna != princesa; coluna++){
            scanf(" %d", &matrizVoto[linha][coluna]);
        }
    }
    for (coluna=0; coluna != princesa; coluna++){
        for (linha=0; linha != eleitores; linha++){
            voto = matrizVoto[linha][coluna] + voto;
        }
    printf("\nPrincesa %d: %d voto(s)",(coluna+1),voto);
    voto = 0;
    }
	return 0;
}
