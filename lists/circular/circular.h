#ifndef CIRCULAR_H
#define CIRCULAR_H

#include "../singly/linkedLists.h"

/*
    In circular linked list, the last node apoints to the header (first node). 

    ---------------------------- USE CASES -----------------------------------

    To represent edges in a circle or whatever data that is circular

    --------------------------- COMPLEXITY -----------------------------------

    1- Insertions in the beginnig and in the end has O(n) time complexity, because we need
    iterate whole elements to modify the last node

*/


struct node *ins_begin_cir_lk(LinkedList *, int);

void show_c_lk(LinkedList *);

#endif 