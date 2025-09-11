#ifndef QUEUE_L_H
#define QUEUE_L_H

#include "../../lists/singly/linkedLists.h"

struct queue_l {
    LinkedList *begin;
    LinkedList *end; 
};

struct queue_l *create_queue_l();

int emptyQueue_l(struct queue_l *);

struct queue_l *freeQueue_s(struct queue_l *);

void ins_queue_l(struct queue_l *, int);

int remove_queue_l(struct queue_l *);

void show_queue_l(struct queue_l *);

#endif