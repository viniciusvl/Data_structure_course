#include "circular.h"
#include <stdlib.h>
#include <stdio.h>

struct node *ins_begin_cir_lk(LinkedList *l, int value){
    struct node *new = (struct node *) malloc(sizeof(struct node));
    if (!new){
        printf("new value was not created\n");
        return l;
    }
    
    new->info = value;

    if (l == NULL){
        new->prox = new;
        l = new;
        return l;
    }

    struct node *current = l;

    // iterate until last element
    while (current != NULL && current->prox != l){
        current = current->prox;
    }
    current->prox = new;
    new->prox = l;
    l = new;

    return l;
}

void show_c_lk(LinkedList *l){
    struct node *p = l;
    if (!p){
        return;
    }

    while (1){
        if (p->prox == l){
            printf(" %d\n", p->info);
            break;
        }
    
        printf("%d ", p->info);
        p = p->prox;
    }
    
}
