#ifndef STACK_H
#define STACK_H

/*

FUN FACT: "stack overflow" occurs when the maximum size of a stack is reached. For example,
when a recursion is infinty.

-------------------------------- EXPLANATION ------------------------------------------
    A stack is a data structure that: 
        1. Insert elements at the top
        2. Remove elements at the top
    Stacks can be implemented with array or linked lists.

-------------------------------- COMPLEXITY ------------------------------------------

    Insertions and removes: O(1), because we remove elements that are in the top


-------------------------------- APLICATIONS ------------------------------------------

    1. C uses stack to call functions. Each functions has a scope, that is in the top. When
    use recursive, functions only see the variables that are in the top. The return adress is 
    stored in a stack. Therefore, when return values, the program back to the beginning 

    2. Check syntax error in text editor
*/

#define MAX_SIZE 50

typedef struct stack {
    int n;
    int array[MAX_SIZE];
} Stack;

// allocate a stack in the heap and returns a pointer
Stack *create_stack();

void freeStack(Stack *);

void stackPush(Stack *, int);

int stackPop(Stack *);

int stackIsFull(Stack *);

int stackIsEmpty(Stack *);




#endif 
