#include <stdlib.h>
#include "bst.h"

// In BST, if a value if less then the current node, it goes to the left. Otherwise, it goes to the right
// Therefore, we iterate until arrive to node that is immediately greater. In this way, we appoint to the NULL
// side, create a new node and back to the source returning all nodes 
Tree *insert_BST(Tree *t, int value){
    if (empty_tree(t)){
        Tree *new = (Tree *) malloc(sizeof(Tree));
        if (!new){
            printf("Node was not created\n");
            exit(1);
        }

        new->info = value;
        new->left = new->right = NULL;

        return new;
    }

    if (t->info > value){
        t->left = insert_BST(t->left, value);
    } else {
        t->right = insert_BST(t->right, value);
    }

    return t;
}

Tree *remove_leaf_BST(Tree *t, int value){
    if (empty_tree(t)){
        printf("Tree is empty\n");

        return NULL;
    }

    if (value < t->info){
        t->left = remove_BST(t->left, value);
    } else if (value > t->info) {
        t->right = remove_BST(t->right, value);
    } else {
        if (t->left == t->right == NULL){
            free(t);
            return NULL;
        }else {
            printf("Node is not a leaf\n");
        }
    }

    return t;
}