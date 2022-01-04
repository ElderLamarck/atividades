#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

typedef struct node {
    int num;
    struct Node* next;

} Node;

typedef struct pilha{
    Node* head;
} Pilha;

Pilha* createPilha(){
    Pilha* pilha = (Pilha*) malloc(sizeof(Pilha));
    pilha->head = NULL;
    return pilha;
}

void pop(Pilha* pilha){
    Node* pointer = pilha->head;
    pilha->head = pointer->next;
    printf("%d\n", pointer->num);
    free(pointer);
    
}

void push(Pilha* pilha, int num){
    Node* node = (Node*) malloc(sizeof(Node));

    node->num = num;
    node->next = pilha->head;
    pilha->head = node;

}

void Abs(Pilha* pilha){
    Node* pointer = pilha->head;
    int max = 0;
    int min = pointer->num;
    int result;

    while (pointer != NULL){
        if (pointer->num > max){
            max = pointer->num;
        }
        else if (pointer->num < min){
            min = pointer->num;
        } 
        pointer = pointer->next;
    }

        result = max - min;

        printf("%d\n",result); 
    
}

int main(){
    char command[5];
    int num;
    Pilha* p = createPilha();

    while(scanf("%s", command) != EOF){
        if(strcmp(command, "pop") == 0){
            pop(p);
        }

        else if(strcmp(command, "abs") == 0){
            Abs(p);
        }

        else if(strcmp(command, "push") == 0){
            scanf("%d", &num);
            push(p, num);
        }
    }
}