#ifndef TREES_H
#define TREES_H

typedef struct tree {
    int info;
    struct tree *left;
    struct tree *right;
} Tree;

// Receive a value, pointer to left and right. In this way, it's possible contruct a tree from the leaf   
Tree *create_node(int, Tree *, Tree *);

Tree *create_empty_tree();

int empty_tree(Tree *);

Tree *free_tree(Tree *);

void show_tree(Tree *);

int tree_has(Tree *, int value);

#endif