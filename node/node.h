#ifndef _NODE_H_
#define _NODE_H_

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAX_CHILDREN 50

typedef struct node node;

struct node {
	int state_number;
	int value;
	int parent;
	int number_of_children;
	node *children[MAX_CHILDREN];
	int seen_time;
	int depth;
};

char *flag;		// A global flag variable that takes in the argv[1] from the terminal
bool node_comparator(node *a, node *b);		// Comparator function

void swap(node *a, node *b);	// Swaps two nodes
node *init_node(int index);		// Initializes a node

#endif