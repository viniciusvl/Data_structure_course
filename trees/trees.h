#ifndef TREES_H
#define TREES_H

typedef struct tree {
    int info;
    struct tree *left;
    struct tree *right;
} Tree;

Tree *create_tree();

#endif