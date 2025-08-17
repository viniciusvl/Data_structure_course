#include "simpleLists.h"
#include <stdlib.h>
#include <stdio.h>

ListaSimples *create_lst_simples(int size){
    ListaSimples *lista = (ListaSimples *) malloc(sizeof(ListaSimples));

    lista->n = (int *) malloc(sizeof(int) * size);  

    if (lista->n == NULL){
        printf("Nao criou lista\n");
        return NULL;
    }

    lista->ctr = 0;
    lista->ctrMax = size;

    return lista;
}

int clear_list(ListaSimples **l){
    // limpa o array
    free((*l)->n);
    // limpa a struct 
    free(*l);
    // setar o ponteiro l para NULL
    *l = NULL;

    return 1;
}


void insert_begin(ListaSimples *l, int value){
    if (isFull(l)){
        printf("Lista esta cheia");
        return;
    }

    for (int i = l->ctr; i > 0; i--){
        l->n[i] = l->n[i-1];
    }                                  
    l->n[0] = value;
    l->ctr = l->ctr + 1;
}

void insert_end(ListaSimples *l, int valor){
    if (isFull(l)){
        printf("Lista cheia\n");
        return;
    }

    l->n[l->ctr] = valor;
    l->ctr = l->ctr + 1;
}

int isEmpty(ListaSimples *l){
    return l->ctr == 0;
}

int isFull(ListaSimples *l){
    return l->ctr == l->ctrMax;
}

void ordered_insert(ListaSimples *l, int valor){
    if (isFull(l)){
        printf("Lista cheia");
        return;
    }

    int index = 0;
    for (int i = l->ctr; i > 0; i--){
        if (valor > l->n[i-1]){
            index = i;
            break;
        }
        l->n[i] = l->n[i-1];
    }
    l->n[index] = valor;
    l->ctr = l->ctr + 1;
}

void remove_begin(ListaSimples *l){
    if (isEmpty(l)){
        printf("Lista vazia\n");
        return;
    }

    for (int i = 0; i < l->ctr-1; i++){
        l->n[i] = l->n[i+1];
    }
    l->ctr = l->ctr - 1;
}

void remove_end(ListaSimples *l){
    if (isEmpty(l)){
        printf("Lista vazia\n");
        return;
    }

    l->ctr = l->ctr - 1;
}

void remove_element(ListaSimples *l, int valor){
    if (isEmpty(l)){
        printf("Lista vazia\n");
        return;
    }
    
    int existElement = 0, index;
    for (int i = 0; i < l->ctr; i++){
        if (l->n[i] == valor){
            existElement = 1;
            index = i;
            break;
        }
    }

    if (!existElement){
        printf("Este elemento nao existe na lista");
        return;
    }

    for (int i = index; i < l->ctr - 1; i++){
        l->n[i] = l->n[i+1];
    }
    l->ctr = l->ctr - 1;
}

void showList(ListaSimples *l){
    printf("Lista: \n");
    for (int i = 0; i < l->ctr-1; i++){
        printf("%d - ", l->n[i]);
    }

    if (l->ctr != 0){
        printf("%d\n", l->n[l->ctr - 1]);
    }
}

int searchElement(ListaSimples *l, int valor){
    if (isEmpty(l)){
        printf("Lista vazia");
        return -1;
    }

    int index = -1;
    for (int i = 0; i < l->ctr; i++){
        if (l->n[i] == valor){
            index = i;
            break;
        }
    }

    return index;
}