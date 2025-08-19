#ifndef STACK_H
#define STACK_H

/*

OBS: this file implements stack with static arrays
*/

#define MAX_SIZE 50

typedef struct stack {
    int n;
    int array[MAX_SIZE];
} Stack_s;

// allocate a stack in the heap and returns a pointer
Stack_s *create_stack();

void freeStack(Stack_s *);

void stackPush(Stack_s *, int);

int stackPop(Stack_s *);

int stackIsFull(Stack_s *);

int stackIsEmpty(Stack_s *);




#endif 
