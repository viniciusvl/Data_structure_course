#include <stdlib.h>
#include <stdio.h>
#include "stack_s.h"

Stack_s *create_stack(){
    Stack_s *stack = (Stack_s *) malloc(sizeof(Stack_s));
    if (!stack){
        printf("Stack was not allocated in the heap\n");
        return NULL;
    }

    stack->n = 0;

    return stack;
}

void freeStack(Stack_s *s){
    free(s);
}

void stackPush(Stack_s *s, int value){
    if (stackIsFull(s)){
        printf("Stack is full\n");
        return;
    }

    s->array[s->n] = value;
    s->n = s->n + 1;
}

int stackPop(Stack_s *s){
    if (stackIsEmpty(s)){
        printf("Stack is empty\n");
        exit(1);
    }

    int value = s->array[s->n - 1];
    s->n = s->n - 1;

    return value;
}

int stackIsFull(Stack_s *s){
    return s->n == MAX_SIZE;
}

int stackIsEmpty(Stack_s *s){
    return s->n == 0;
}