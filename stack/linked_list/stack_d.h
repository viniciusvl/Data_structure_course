#ifndef STACK_D_H
#define STACK_D_H

/*
    Implement stack with linked list is simply assign a pointer to the first node.

    - Insertions: assing stack pointer to the first node and manipulate others pointer

    - Remove: assing stack pointer to the next node and free 

    All functions are O(1)
*/

struct node {
    int info;
    struct node *prox;
};

typedef struct stack_l {
    struct node *header;
} Stack_l;

Stack_l *create_stack_l();

void freeStack_l(Stack_l *);

void *stackPush_l(Stack_l *, int);

int isEmpty_l(struct node *);

int stackPop_l(Stack_l *);

void showStack_l(Stack_l *);

#endif