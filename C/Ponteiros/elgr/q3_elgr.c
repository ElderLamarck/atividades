#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

typedef struct node {
    int id;
    int idade;
    struct Node* next;

} Node;

typedef struct fila {
    Node* ini;
    Node* fim;
}Fila;

Fila* createFila(){
    Fila* fila = (Fila*) malloc(sizeof(Fila));
    fila->ini = NULL;
    fila->fim = NULL;
    return fila;
}

void push(Fila* fila, int id, int idade){
    Node* node = (Node*) malloc(sizeof(Node));

    node->id = id;
    node->idade = idade;
    node->next = NULL;

    if(fila->ini == NULL){
        fila->ini = node;
    }else{
        fila->fim->next = node;
    }
    fila->fim = node;
}

void removeNode(Fila* fila){
    Node* pointer = fila->ini;
    if (pointer == NULL){
        return;
    }else{
    fila->ini = pointer->next;
    free(pointer);        
    }
}

void filaValues(Fila* filaIdoso, Fila* filaJovem){
    Node* pointerIdoso = filaIdoso->ini;
    Node* pointerJovem = filaJovem->ini;

    printf("\nfila de idosos:\n");
    
    if (pointerIdoso == NULL){
        printf("fila vazia!\n");
    }
    
    while(pointerIdoso != NULL){
        printf("ID: %d IDADE: %d\n", pointerIdoso->id, pointerIdoso->idade);
        pointerIdoso = pointerIdoso->next;
    }

    printf("fila de nao-idosos:\n");
        if (pointerJovem == NULL){
        printf("fila vazia!\n");
    }

    while(pointerJovem != NULL){
        printf("ID: %d IDADE: %d\n", pointerJovem->id, pointerJovem->idade);
        pointerJovem = pointerJovem->next;
    }
    printf("----------\n");
}

void debugFila(Fila* fila){
    Node* pointer = fila->ini;
    while (pointer != NULL){
        printf("id-%d//idade-%d\n", pointer->id, pointer->idade);
        pointer = pointer->next;
    }
}

int main(){
    char command[1];
    int idade;
    int ID;
    int priority;
    int count = 0;
    
    Fila* filaIdoso = createFila();
    Fila* filaJovem = createFila();
    

    scanf("%d", &priority);

    while(strcmp(command, "f") != 0){
        scanf("%s", command);

        if (strcmp(command, "a") == 0){
            scanf("%d", &ID);
            scanf("%d", &idade);

            if(idade > 60){
                push(filaIdoso, ID, idade);

            }else{
                push(filaJovem, ID, idade);
            }
        }

        if (strcmp(command, "r") == 0){
            if (count == priority || filaIdoso->ini == NULL){
                count = 0;
                removeNode(filaJovem);
            }else{
                removeNode(filaIdoso);
                count++;
            }
        }

        if (strcmp(command, "i") == 0){
            filaValues(filaIdoso, filaJovem);
        }
    }

}