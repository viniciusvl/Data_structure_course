#ifndef LINKED_LISTS_H
#define LINKED_LISTS_H

// Uma lista se constitui de uma séria de structs que possuem dois elementos:
//  - A informação que queremos guardar 
//  - Ponteiro para outra struct 
// Assim, conseguimos montar uma série de dados que possuem relação entre si através de ponteiros
//o ponto positivo é que conseguimos montar dinamicamente, alocando apenas o necessário


// --------------------- Advantges --------------------------
//  1 - Inset elements at linked list is more efficiently than insert in Array, because we don't need
// make shift to move the elements. Therefore, the linked list's time complexity for insertion
// is O(1) in the any case, whereas array's time complexity is O(n) in the worst case

//  2 - Space allocation: the memory required to make a linked list is dinamyc, whereas in arrays,
// the memory required is static. Therefore, when an array is assigned, the whole memory is allocated
// for every element, even though the array is empty 

// --------------- Disadvantages ----------------------
//  1 - Search an element in a linked list is O(n), because we need to iterate each element in the list
//  2 - Cache inefficieny: the linked is not contiguos in the memory. So, it's dificult make cache.

typedef struct node {
    int info;
    struct node *prox;
} LinkedList;

LinkedList *create_linked_lst();

void free_lk(struct node **);

LinkedList *ordered_insert_lk(struct node *, int);

void insert_begin_lk(struct node **, int);

void insert_end_lk(struct node *, int);

void remove_begin_lk(struct node **);

LinkedList *remove_end_lk(struct node *l);

LinkedList *remove_element_lk(struct node *, int value);

// return index, -1 there is no the elemente in list
int searchElement_lk(struct node *, int);

void show_lk(struct node *);

#endif