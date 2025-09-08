#include <stdlib.h>
#include <stdio.h>
#include "stack_s.h"

// Stack with array has 2 elemments: an array and a controller 
// controller is the last index of the array 


// create stack with variable sizes
Stack_s *create_stack(int size){
    Stack_s *s = (Stack_s *) malloc(sizeof(Stack_s));
    if (!s){
        printf("It was not created stack\n");
        exit(1);
    }

    s->array = (int *) malloc(sizeof(int) * size);
    if (!s->array){
        printf("It was not created stack's array\n");
        exit(1);
    }

    s->n = 0;
    s->size = size;

    return s;
}

// An stack insert elements at the top
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

void freeStack(Stack_s **s){
    free((*s)->array);
    
    free((*s));

    *s = NULL;
}

void showStack(Stack_s *s){
    if (stackIsEmpty(s)){
        return;
    }

    int top = s->n;
    while (top--){
        printf("%d ", s->array[top]);
    }
    printf("\n");
}

int stackIsEmpty(Stack_s *s){
    return s->n == 0;
}

int stackIsFull(Stack_s *s){
    return s->n >= s->size;
}