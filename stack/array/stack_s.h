#ifndef STACK_S_H
#define STACK_S_H

/*

OBS: this file implements stack with static arrays
*/


typedef struct stack {
    int n;
    int *array; // a pointer to the stack. it allow us to define any size to stack
    int size;
} Stack_s;

// allocate a stack in the heap and returns a pointer
Stack_s *create_stack(int);

void freeStack(Stack_s **);

void stackPush(Stack_s *, int);

int stackPop(Stack_s *);

int stackIsFull(Stack_s *);

void showStack(Stack_s *);

int stackIsEmpty(Stack_s *);




#endif 
