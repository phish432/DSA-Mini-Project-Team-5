#include "node.h"

bool node_comparator(node *a, node *b) {
    node x = *a;
    node y = *b;

    if (x.value > y.value)  return true;
    else return false;
}

void swap(node *a, node *b) {
    node *c = (node *)malloc(sizeof(node));
    memcpy(c, a, sizeof(node));
    memcpy(a, b, sizeof(node));
    memcpy(b, c, sizeof(node));
}

node *init_node(int index) {
    node *ptr = (node *)malloc(sizeof(node));
    ptr->state_number = index;
    ptr->value = -1;
    ptr->parent = -1;
    ptr->number_of_children = 0;
    for (int i = 0; i < MAX_CHILDREN; i++) {
        ptr->children[i] = NULL;
    }
    return ptr;
}