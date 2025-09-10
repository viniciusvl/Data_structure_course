#include "queue.h"
#include <stdio.h>
#include <stdlib.h>

struct queue_s *create_queue_s(int size){
    struct queue_s *q = (struct queue_s *) malloc(sizeof(struct queue_s));
    if (!q){
        printf("Queue was not created\n");
        exit(1);
    }

    q->array = (int *) malloc(sizeof(int) * size);
    if (!q->array){
        printf("Array was not created\n");

        free(q);
        exit(1);
    }

    q->n = 0;
    q->begin = 0;

    return q;
}

int emptyQueue(struct queue_s *q){
    return !q || q->n == 0;
}

struct queue_s *freeQueue_s(struct queue_s *q){
    if (emptyQueue(q)){
        printf("Queue is empty\n");
        exit(1);
    }

    free(q->array);
    free(q);

    return NULL;
}

int fullQueue(struct queue_s *q){
    return q->n == q->MAX;
}

void ins_queue_s(struct queue_s *q, int value){
    if (fullQueue(q)){
        printf("Queue is full\n");
        return;
    }

    // we count index begin + size of queue
    int end = (q->begin + q->n) % q->MAX;

    q->array[end] = value;
    q->n++;
}

int remove_queue_s(struct queue_s *q){
    if (emptyQueue(q)) {
        printf("Queue is empty\n");
        exit(1);
    }

    int value = q->array[q->begin];
    q->begin = (q->begin + 1) % q->MAX;
    q->n--;

    return value;
}

void showQueue(struct queue_s *q){
    if (emptyQueue(q) || !q){
        printf("Queue is empty\n");
        return;
    }

    int i = q->begin;
    int times = q->n;

    while (times--){
        printf("%d ", q->array[i]);

        i = (i + 1) % q->MAX;
    }
    printf("\n");
}