#ifndef _TREE_H_
#define _TREE_H_

#include "../node/node.h"

#define MAX_TREE_SIZE 1000

typedef struct tree tree;

struct tree {
    int number_of_nodes;
    node *nodes[MAX_TREE_SIZE];
};

tree *init_tree();
void create_tree(tree *root, int size, node *input[]);
void print_tree(tree *root);

#endif