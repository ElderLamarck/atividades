#include <stdio.h>
#include <stdlib.h>
#include <math.h>


int main() {
    int linhaT, colunaT;
    int linhaValor, colunaValor;
    int diagonalP = 0, diagonalS = 0;
    int menorZero = 0, maiorZero = 0;
    int matriz[100][100];

    scanf("%d %d",&colunaT,&linhaT);

    for(colunaValor = 0 ;colunaValor < colunaT ;colunaValor++){
        for(linhaValor = 0 ;linhaValor < linhaT ;linhaValor++){
            scanf("%d", &matriz[colunaValor][linhaValor]);
            if(matriz[colunaValor][linhaValor] > 0){
                maiorZero++;
            } else {
                menorZero++;
            }
        }
    }
    printf("Matriz formada:");
    for(colunaValor = 0 ;colunaValor < colunaT ;colunaValor++){
        printf("\n");
        for(linhaValor = 0 ;linhaValor < linhaT ;linhaValor++){
            printf("%d ", matriz[colunaValor][linhaValor]);
        }
    }

    colunaValor = 0;
    linhaValor = 0;

    if (linhaT != colunaT){
        printf("\nA diagonal principal e secundaria nao pode ser obtida.");
    }else{
        while (linhaValor <= linhaT && colunaValor <= colunaT){
            diagonalP = matriz[colunaValor][linhaValor] + diagonalP;
            colunaValor++;
            linhaValor++;
        }
        colunaValor = 0;
        linhaValor = linhaT - 1;
        
        while (linhaValor >= 0 && colunaValor <= colunaT){
            diagonalS = matriz[colunaValor][linhaValor] + diagonalS;
            colunaValor++;
            linhaValor--;
        }
        printf("\nA diagonal principal e secundaria tem valor(es) %d e %d respectivamente.", diagonalP,diagonalS);
        printf("\nA matriz possui %d numero(s) menor(es) que zero.", menorZero);
        printf("\nA matriz possui %d numero(s) maior(es) que zero.", maiorZero);
    }
}