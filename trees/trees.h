#ifndef TREES_H
#define TREES_H

typedef struct tree {
    int info;
    struct tree *left;
    struct tree *right;
} Tree;

// Receive value, pointer to left and right. In this way, it's possible contruct a tree from the leaf   
Tree *create_node(int, Tree *, Tree *);

Tree *create_empty_tree();


#endif