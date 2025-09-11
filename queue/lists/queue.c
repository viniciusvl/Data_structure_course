#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

struct queue_l *create_queue_l(){
    struct queue_l *q = (struct queue_l *) malloc(sizeof(struct queue_l));
    if (!q){
        printf("Queue was not created\n");
        exit(1);
    }

    q->begin = q->end = NULL;

    return q;
}

int emptyQueue_l(struct queue_l *q){
    return !q || q->begin == NULL;
}

void freeList(LinkedList *l){
    if (l->prox != NULL){
        freeList(l->prox);
    }

    free(l);
}

struct queue_l *freeQueue_l(struct queue_l *q){
    if (emptyQueue_l(q)){
        printf("Queue is empty\n");
        exit(1);
    }

    freeList(q->begin);
    q->begin = q->end = NULL;

    return NULL;
}

void ins_queue_l(struct queue_l *q, int value){
    LinkedList *new = (LinkedList *) malloc(sizeof(LinkedList));
    if (!new){
        printf("Node was not created\n");

        return;
    }

    new->prox = NULL;
    new->info = value;

    if (!q->begin){
        q->begin = new;
    } else {
        q->end->prox = new;
    }

    q->end = new;
}

int remove_queue_l(struct queue_l *q){
    if (emptyQueue_l(q)){
        printf("Queue is empty\n");
        exit(1);
    }

    int value = q->begin->info;
    struct node *remove = q->begin;

    if (q->begin == q->end){
        q->end = NULL;
    }
    
    q->begin = q->begin->prox;
    
    free(remove);
    
    return value;
}

void show_queue_l(struct queue_l *q){
    if (emptyQueue_l(q)){
        printf("Queue is empty\n");
        return;
    }

    struct node *aux = q->begin;

    for (aux = q->begin; aux != NULL; aux = aux->prox){
        printf("%d ", aux->info);
    }
    printf("\n");
}