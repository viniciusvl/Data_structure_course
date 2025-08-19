#include "stack_d.h"
#include <stdio.h>
#include <stdlib.h>

Stack_d *create_stack_d(){
    Stack_d *s = (Stack_d *) malloc(sizeof(Stack_d));
    s->header = NULL;

    return s;
}

void free_d(Stack_d *s){
    lista *l = s->header,
          *aux = NULL;

    while (l != NULL){
        aux = l;
        l = l->prox;

        free(aux);
    }
    free(s);
}

Stack_d *push_d(Stack_d *s, int value){
    lista *newHeader = (lista *) malloc(sizeof(lista));
    if (!newHeader){
        printf("New value was not created\n");
        return s;
    }

    newHeader->info = value;
    newHeader->prox = s;
    
    return newHeader;
}

int pop_d(Stack_d *s){
    if (!s->header){
        printf("Stack is empty\n");
        exit(1);
    }

    // store removed node to make free
    lista *remNode = s->header;

    int remValue = remNode->info;

    // appoints stack pointer to the next node of the list
    s->header = s->header->prox;

    free(remNode);

    return remValue;
}