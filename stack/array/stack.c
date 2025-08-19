#include <stdlib.h>
#include <stdio.h>
#include "stack.h"

Stack *create_stack(){
    Stack *stack = (Stack *) malloc(sizeof(Stack));
    if (!stack){
        printf("Stack was not allocated in the heap\n");
        return NULL;
    }

    stack->n = 0;

    return stack;
}

void freeStack(Stack *s){
    free(s);
}

void stackPush(Stack *s, int value){
    if (stackIsFull(s)){
        printf("Stack is full\n");
        return;
    }

    s->array[s->n] = value;
    s->n = s->n + 1;
}

int stackPop(Stack *s){
    if (stackIsEmpty(s)){
        printf("Stack is empty\n");
        exit(1);
    }

    int value = s->array[s->n - 1];
    s->n = s->n - 1;

    return value;
}

int stackIsFull(Stack *s){
    return s->n == MAX_SIZE;
}

int stackIsEmpty(Stack *s){
    return s->n == 0;
}