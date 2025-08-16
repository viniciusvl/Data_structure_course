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


LinkedList *remove_element_lk(struct node *l, int value){
    if (is_empty_lk(l)){
        printf("List is empty");
        return l;
    }

    struct node *p = l,
                *ant = NULL;
    
    while(p != NULL && p->info != value){
        ant = p;
        p = p->prox;
    }

    if (p == NULL){
        printf("Value %d is not in the list\n", value);
        return l;
    }

    // if has not ant, so there is only one element
    if (!ant){
        l = p->prox;
    } else {
        ant->prox = p->prox;
    }

    free(p);

    return l;
}


void free_lk(struct node **l){
    if (is_empty_lk(*l)){
        printf("List is empty");
        return;
    }

    struct node *p = *l,
                *current = NULL;

    while (p != NULL){
        current = p;
        p = p->prox;

        free(current);
    }
    free(*l);
    *l = NULL;
}


int searchElement_lk(struct node *l, int value){
    struct node *current = l;
    int i;

    for (i = 0; current != NULL && current->info != value; i++, current = current->prox);

    return (current != NULL) ? i : -1;
}

void show_lk(struct node *header){
    struct node *current;

    for (current = header; current != NULL; current = current->prox){
        printf("%d ", current->info);
    }

    if (current){
        printf("\n");
    }
}

