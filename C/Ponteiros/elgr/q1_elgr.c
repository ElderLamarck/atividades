#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

typedef struct dataNode {
    char name[20];
    float value;
    int quant;
    
} DataNode;

typedef struct node {
    DataNode data;
    struct node* next;
} Node;

typedef struct list{
    Node* head;
} List;

List* createList(){
    List* list = (List*) malloc(sizeof(List));
    
    list->head = NULL;

    return list;
}

void printTotalValue (List* list){
    Node* pointer = list->head;
    float count = 0;
    while (pointer != NULL){
        count = ((pointer->data.quant) * (pointer->data.value)) + count;
        pointer = pointer->next;
        
    }
    printf("Atualmente a lista esta em R$%.1f\n\n", count);
}

void push(List* list, DataNode data){
    Node* node = (Node*) malloc(sizeof(Node));

    node->data = data;
    node->next = list->head;
    list->head = node;

}

void removeItem(List* list, char name[20], int quantidade){
    Node* pointer = list->head;
    Node* atNode = list;
    Node* preNode = pointer;

    while (pointer != NULL){
        if (strcmp(pointer->data.name,name) == 0){
        pointer->data.quant = pointer->data.quant - quantidade;
            if (pointer->data.quant <= 0){
                atNode = pointer;
                preNode->next = atNode->next;
                free(atNode);
            }
        }
        preNode = pointer;
        pointer = pointer->next;
    }
}

void Search(List* list, char name[20]){
    Node* pointer = list->head;

    while (pointer->next != NULL){
        printf("item: %s\n", pointer->data.name);
        if (strcmp(pointer->data.name, name) == 0){
            printf("\n%s\n- %.1f\n- %d\n", pointer->data.name, pointer->data.value, pointer->data.quant);
            return;
        }
        pointer = pointer->next;
        if (pointer->next == NULL){
            printf("\n%s nao foi encontrado.\n", name);
        }
        
    }
}

void pop(List* list){
    Node* pointer = list->head;
    list->head = pointer->next;
    free(pointer);
}

void removeAll(List* list, float valor){
    Node* pointer = list->head;
    Node* preNode = pointer;
    Node* atNode = list;
    int index = 0;
    int adc = 0;

    while (pointer != NULL){
        if (pointer->data.value > valor){
            if (index == 0){
                pop(list);
                adc = 0;
                debugger(list);
            }
            else{
                atNode = pointer;
                preNode->next = atNode->next;
                free(atNode);
                debugger(list);
                adc = 1;
            }
        }                                                                    
        if (adc >= 1){index++;}

        preNode = pointer;
        pointer = pointer->next;
    }
     
}

void debugger(List* list){
    Node* pointer = list->head;
    while (pointer != NULL){
        printf("\nnome:%s\nvalor:%f\nquant:%d\nponteiro:%d\n", pointer->data.name,pointer->data.value,pointer->data.quant,pointer);
        pointer = pointer->next;
    }
}


int main() {
    char command[20];
    char name[20];
    int key;
    float value;
    int quant;

    List* l = createList();
    DataNode data;

    while (scanf("%s", command) != EOF){

        key = strcmp(command, "INSERIR");
        if (key == 0){
            scanf("%s", data.name);
            scanf("%f", &value);
            scanf("%d", &quant);

            data.quant = quant;
            data.value = value;
            push(l, data);
        }

        key = strcmp(command, "REMOVER");
        if (key == 0){
            scanf("%s", name);
            scanf("%d", &quant);
            removeItem(l,name,quant);
        }

        key = strcmp(command, "REMOVERGRUPO");
        if (key == 0){
            scanf("%f", &value);
            removeAll(l, value);
        }
        
        key = strcmp(command, "CONSULTAR");
        if (key == 0){
            printTotalValue(l);
            debugger(l);
        }
        
        key = strcmp(command, "PROCURAR");
        if (key == 0){
            scanf("%s", name);
            Search(l, name);
        }
    }
	return 0;
}