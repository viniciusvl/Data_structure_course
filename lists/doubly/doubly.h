#ifndef DOUBLY_H
#define DOUBLY_H

#include "../singly/linkedLists.h"

/*
-------------------------------- EXPLANATION ------------------------------------------

    Doubly linked lists are composed by 3 elements: 
        1. Data
        2. A pointer to the previous element
        3. A pointer to the next element
    The previous pointer of the first node is NULL, while the last node one is NULL. 

-------------------------------- ADVANTAGES ------------------------------------------

    1. We can move through the list both directions 
    2. Insertions and removes:
        - Beginning: O(1), because we need modify pointer values
        - Middle: O(n), because we need iterate each node until found the expected value
        - End: O(n), it's necessary iterate all list

-------------------------------- APLICATIONS ------------------------------------------

    1. Undo and redo: text editors use doubly linked list to save user's modifications
    2. Browser history: to navigate back and foward in web browser

*/


typedef struct doubly {
    int info;
    Doubly_LK *ant; 
    Doubly_LK *prox;
} Doubly_LK;

void free_doubly(struct doubly *);

struct doubly *ins_begin_doubly(struct doubly *, int);

struct doubly *ordered_ins(struct doubly *, int);

struct doubly *rem_begin(struct doubly *, int);

struct doubly *rem_element(struct doubly *, int);


#endif 