#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {
    int lineT, columnT;
    int line, column;
    int linha, coluna;
    int ini = 1, meio, fim;
    int totalV;

    scanf("%d %d", &lineT, &columnT);
    int matriz[lineT][columnT];
    fim = (lineT*columnT);

    for (line=0; line != lineT; line++){
        for (column=0; column != columnT; column++){ 
            scanf(" %d", &matriz[line][column]);
        }
    }


    scanf("%d", &totalV);
    int valuesV[totalV];
    

    for (int j = 0; j != totalV; j++){
        scanf(" %d", &valuesV[j]);
    }

	for (int j = 0; j != totalV; j++){
        while(ini<=fim){ 
            meio=(ini+fim)/2;

            if ((meio % columnT) == 0){
                linha = (meio/columnT);
                coluna = 0;
            }
            else{
                linha = (meio/columnT);
                coluna = meio % columnT;

            }
        
            if(matriz[linha][coluna] == valuesV[j]){
                printf("YES WITH %d AND %d\n", linha+1, coluna+1);
                break;
            } 
            if(matriz[linha][coluna] < valuesV[j]){
                ini=meio+1;
                
            }  
            if(matriz[linha][coluna] > valuesV[j]){
                fim=meio-1;
            }
        }
    if(matriz[linha][coluna] != valuesV[j]){
            printf("NO\n");
        }
    ini = 1;
    fim = (lineT*columnT);
    }
    return 0;
}