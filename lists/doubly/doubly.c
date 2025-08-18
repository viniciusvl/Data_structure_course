#include <stdio.h>
#include <stdlib.h>
#include "doubly.h"

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
