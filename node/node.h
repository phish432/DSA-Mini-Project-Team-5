#ifndef _NODE_H_
#define _NODE_H_

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAX_CHILDREN 1000

typedef struct node node;

struct node {
    int state_number;
    int value;
    int parent;
    int number_of_children;
    node *children[MAX_CHILDREN];

    // You (as a developer) can add any extra information here [Will not be touched by user]
    // int depth;
    // int seen_time;
};

bool node_comparator(node *a, node *b);
void swap(node *a, node *b);
node *init_node(int index);

#endif