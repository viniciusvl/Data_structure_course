#include <stdio.h>
#include <stdlib.h>
#include "trees.h"

Tree *create_empty_tree(){
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

Tree *free_tree(Tree *t){
    // This function knows that a node is a leaf when left and right side points to NULL
    // Firstly, it iterates through the left side of the tree until to arrive a leaf
    // So, it iterates through right side until a leaf  

    if (!empty_tree(t)){
        free_tree(t->left);
        free_tree(t->right);

        free(t);
    }

    return NULL;
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

void show_tree_direto(Tree *t){
    if (!empty_tree(t)){
        show_tree_direto(t->left);

        printf("%d ", t->info);
        
        show_tree_direto(t->right);
    }
}

// verify if a tree has a value
int tree_has(Tree *t, int value) {
    if (empty_tree(t)){
        return 0;
    }
    // This search don't iterate over whole tree. It stops when the target is found
    // because if t->info is true, the program don't evaluate the whole expression
    // This also happens with others elements
    return t->info == value || tree_has(t->left, value) || tree_has(t->right, value); 
}