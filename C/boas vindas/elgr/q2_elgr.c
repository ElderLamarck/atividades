#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {
    int valorF;
    int notas[7] = {100, 50, 20, 10, 5, 2, 1};
    int moedas[5] = {50, 25, 10, 05, 01};
    float quant, resto, valorI, resposta;
    int i = 0;

    scanf("%f",&valorI);
    valorF = valorI*100;

    while (i < 7){
        while(valorF / (notas[i]*100) > 0){
            quant = valorF / (notas[i]*100);
            resto = valorF % (notas[i]*100);
            if (notas[i] == 1){
                printf("%.f moeda(s) de R$ %d.00\n", quant,notas[i]);
            }else{
                printf("%.f nota(s) de R$ %d.00\n", quant,notas[i]);
            }
            valorF = resto;
        }
        i++;
    }
    i = 0;
    while (i < 5){
        if(valorF / (moedas[i]) > 0){
            quant = valorF / moedas[i];
            resto = valorF % moedas[i];
            if (moedas[i] > 6){
                 printf("%.f moeda(s) de R$ 0.%d\n", quant, moedas[i] );
            }else{
                printf("%.f moeda(s) de R$ 0.0%d\n", quant, moedas[i] );
            }
            valorF = resto;
        }
        i++;
    }
    return 0;
}