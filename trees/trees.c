#include <stdio.h>
#include <stdlib.h>
#include "trees.h"

Tree *create_empty_tree(){
    return NULL;
}

Tree *free_tree(Tree *t){
    // This function knows that a node is a leaf when left and right side points to NULL
    // Firstly, it iterates through the left side of the tree until to arrive a leaf
    // So, it iterates through right side until a leaf  

    if (!empty_tree(t)){
        free_tree(t->left);
        free_right(t->right);

        free(t);
    }

    return NULL;
}

Tree *create_node(int value, Tree *left, Tree *right) {
    Tree *t = (Tree *) malloc(sizeof(Tree));
    if (!t) {
        printf("Node was not created\n");
        return NULL;
    }

    t->info = value;
    t->left = left;
    t->right = right;

    return t;
}

int empty_tree(Tree *t){
    // When a tree is NULL, so it is empty
    return t == NULL;
}


void show_tree(Tree *t){
    // if tree is NOT empty
    if (!empty_tree(t)){
        printf("%d ", t->info);

        // call left branch until t = NULL, i.e, show all elements from left 
        show_tree(t->left);
        // when finish show left side, show right side
        show_tree(t->right);
        // Nodes that only has right side are showed to
    }   
}