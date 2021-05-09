#ifndef _TREE_H_
#define _TREE_H_

#include "../node/node.h"

#define MAX_TREE_SIZE 100005

typedef struct tree tree;

struct tree {
	int size;
	node *nodes[MAX_TREE_SIZE];
};

tree *init_tree();	// Initializes tree
void create_tree(tree *T, int size, node input[]);	// Creates a tree from a given input array
void print_tree(tree *T);	// Printing the tree
void destroy_tree(tree *T);

#endif