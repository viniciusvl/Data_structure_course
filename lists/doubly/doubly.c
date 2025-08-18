#include <stdio.h>
#include <stdlib.h>
#include "doubly.h"

void free_doubly(struct doubly *l){
    
}

struct doubly *ins_begin_doubly(struct doubly *l, int value){
    struct doubly *new = (struct doubly *) malloc(sizeof(struct doubly));
    if (!new){
        printf("The new value was not created\n");
        return l;
    }

    new->info = value;
    new->prox = l;
    new->ant = NULL;
    
    if (l != NULL){
        l->ant = new;
    }

    // return new, because it will substitute l value
    return new;
}

struct doubly *ordered_ins(struct doubly *l, int value){
    struct doubly *new = (struct doubly *) malloc(sizeof(struct doubly));
    if (!new){
        printf("New value was not created\n");
        return l;
    }

    new->info = value;

    if (l == NULL){
        new->prox = NULL;
        new->ant = NULL;

        return new;
    }

    struct doubly *current = l;
    while (current->info < value && current->prox != NULL){
        current = current->prox;
    }

    // if is in the beginning
    if (current == l){
        new->prox = current;
        new->ant = NULL;

        current->ant = new;

        return new;
    }

    // if its in the final
    if (current->prox == NULL){
        current->prox = new;
        
        new->ant = current;
        new->prox = NULL;
    } else {
        new->ant = current->ant;
        new->prox = current;

        current->ant->prox = new;
        current->ant = new;
    }

    return l;
}

struct doubly *rem_begin(struct doubly *l, int value){

}

struct doubly *rem_element(struct doubly *l, int value){

}


