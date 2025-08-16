#include <stdio.h>
#include <stdlib.h>
#include "linkedLists.h"

// To create a list, it's necessary retun a NULL pointer
LinkedList *create_linked_lst(){
    return NULL;
}

void insert_begin_lk(struct node **header, int value){
    struct node *new = (struct node *) malloc(sizeof(struct node));
    if (!new){
        printf("Don't create a new value");
        return;
    }

    new->info = value;
    new->prox = *header; // receive the value that the header was appointing 
    *header = new; // assing new's adress value, i.e, the struct node value 

    // Don't free new, because it will erase struct node, that is in the heap
} 

void insert_end_lk(struct node *l, int value){ 
    struct node *new = (struct node *) malloc(sizeof(struct node));
    if (!new){
        printf("Don't create a new value");
        return;
    }

    new->info = value;
    new->prox = NULL;

    // iterate each element until end
    struct node *current;
    for (current = l; current->prox != NULL; current = current->prox);

    current->prox = new;
}   

int is_empty_lk(struct node *l){
    return l == NULL;
}

void remove_begin_lk(struct node **header){
    if (is_empty_lk(*header)){
        printf("List is empty");
        return;
    }

    struct node *nodeToRemove = *header;
    *header = (*header)->prox;

    free(nodeToRemove);
}

LinkedList *remove_end_lk(struct node *l){
    if (is_empty_lk(l)){
        printf("List is empty");
        return l;
    }

    struct node *p = l, 
                *ant = NULL;

    while(p->prox != NULL){
        ant = p;
        p = p->prox;
    }

    if (!ant){
        l = NULL;
    } else {
        ant->prox = NULL;
    }

    free(p);

    return l;
}

int remove_element_lk(struct node *l){
    
}



void show_lk(struct node *header){
    struct node *current;

    for (current = header; current != NULL; current = current->prox){
        printf("%d ", current->info);
    }
    if (current){
        printf("/n");
    }
}

