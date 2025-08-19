#include <stdio.h>
#include <stdlib.h>
#include "doubly.h"

void free_doubly(struct doubly *l){
    if (is_empty_lk(l)){
        printf("The list is empty\n");
        return l;
    }

    struct doubly *p = l->prox,
                  *ant = NULL;
    
    while (p != NULL){
        ant = p;
        p = p->prox;

        free(ant);
    }
    free(l);
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
    if (is_empty_lk(l)){
        printf("The list is empty\n");
        return l;
    }

    struct doubly *nodeToRem = l;

    l->prox->ant = NULL;
    l = l->prox;

    free(nodeToRem);

    return l;
}

struct doubly *rem_element(struct doubly *l, int value){
    if (is_empty_lk(l)){
        printf("The list is empty\n");
        return l;
    }

    struct doubly *current = l;
    while (current->info != value && current != NULL){
        current = current->prox;
    }

    if (!current){
        printf("Value is not in the list\n");
        return l;
    }
        
    if (current->ant == NULL){
        if (current->prox != NULL){
            l->prox->ant = NULL;
        }

        l = l->prox;
    } else {
        current->ant->prox = current->prox;
        current->prox->ant = current ->ant;
    }

    free(current);
}


