#include <stdio.h>
#include <stdlib.h>
#include <operaArray.h>

int main ()
{   
    int value;
    int tamanho;
    char escolha;
    int i = 0;

    printf("Digite o tamanho do array\n");
    scanf("%d",tamanho);
    int array[tamanho];
    
    printf("Digite os elementos:\n");
   	while (i != tamanho){
		scanf(" %d", &value);
        array[i] = value;
		i++;
       }

    while (escolha != "s"){
    
        printf("Menu de opções :\n");
        printf("R = inverter a lista"); 
        printf("E = contar numero de vezes que um elemento aparece no array");
        printf("U = retornar apenas elementos que não se repetem ");
        printf("D = deletar o enésimo elemento do array");
        printf("S = sair do menu\n");

        scanf("%c",&escolha);

        if (escolha == 'R'){
            int new[tamanho];
            newReverse(array, tamanho);

            for(i = 0; i <= (tamanho - 1); i++){
                printf("%d, ", new[i]);
            }
        }

        else if (escolha == 'E'){
            printf("Informe o numero:");
            int num;
            scanf("%d", &num);
            elemNum(array, tamanho, num);
        }

        else if (escolha == 'U'){
            unique(*array, tamanho);
        }

        else if (escolha == 'D'){
            printf("Informe o valor:");
            int position;
            scanf("%d", &position);
            deleteN(array, tamanho, position);
        }
    }
    printf("deseja salvar as respostas em um arquivo de texto? [s/n]");
    scanf("%c", &escolha);
    if (escolha == 's'){
    }

    return 0;
}