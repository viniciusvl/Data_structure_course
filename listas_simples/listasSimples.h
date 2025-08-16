#ifndef LISTAS_SIMPLES_H
#define LISTAS_SIMPLES_H

typedef struct l{
    int ctr;
    int ctrMax;
    int *n;
} ListaSimples;
 
ListaSimples *create_lst_simples(int);

// retorna 1 se limpou
int clear_list(ListaSimples **);

void insert_begin(ListaSimples *, int);

void insert_end(ListaSimples *, int);

int isEmpty(ListaSimples *);

int isFull(ListaSimples *);

void ordered_insert(ListaSimples *, int);

void remove_begin(ListaSimples *);

void remove_end(ListaSimples *);

void remove_element(ListaSimples *, int);

void showList(ListaSimples *);

// retorna o índice do elemento se encontrou ou -1 se nao encontrou
int searchElement(ListaSimples *, int);

#endif