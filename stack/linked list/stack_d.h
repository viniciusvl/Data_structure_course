#ifndef STACK_D_H
#define STACK_D_H

/*
    Implement stack with linked list is simply assign a pointer to the first node.

    - Insertions: assing stack pointer to the first node and manipulate others pointer

    - Remove: assing stack pointer to the next node and free 

    All functions are O(1)
*/

struct l {
    int info;
    struct l* prox;
} typedef lista;

struct stack_d {
    lista *header;
} typedef Stack_d;


void free_d(Stack_d *);

Stack_d *create_stack_d();

Stack_d *push_d(Stack_d *, int);

int pop_d(Stack_d *);

#endif