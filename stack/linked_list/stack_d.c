#include "stack_d.h"
#include <stdio.h>
#include <stdlib.h>

Stack_l *create_stack_l(){
    Stack_l *s = (Stack_l *) malloc(sizeof(Stack_l)); 
    if (!s){
        printf("Stack was not created\n");

        exit(1);
    }

    s->header = NULL;

    return s;
}

void freeList(struct node *l){
    if (l->prox != NULL){
        freeList(l->prox);
    }

    free(l);
}

void freeStack_l(Stack_l *s){
    if (!s->header){
        printf("Stack is empty\n");
        return;
    }

    freeList(s->header);

    s->header = NULL;
}


void *stackPush_l(Stack_l *s, int value){
    struct node *new = (struct node *) malloc(sizeof(struct node));
    if (!new){
        printf("Node was not created\n");

        return s;
    }

    new->info = value;

    new->prox = s->header;
    s->header = new;
}

int stackPop_l(Stack_l *s){
    if (isEmpty_l(s->header)){
        printf("Stack is empty\n");
        exit(1);
    }

    struct node *remove = s->header;
    
    int value = s->header->info;

    s->header = s->header->prox;

    free(remove);

    return value;
}

int isEmpty_l(struct node *l){
    return l == NULL;
}


void showStack_l(Stack_l *s){
    if (isEmpty_l(s->header)){
        printf("Stack is empty\n");
        
        return;
    }
    
    struct node *aux;

    for (aux = s->header; aux != NULL; aux = aux->prox){
        printf("%d ", aux->info);
    }
    printf("\n");
}

