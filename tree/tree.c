#include "tree.h"

tree *init_tree() {
    tree *root = (tree *)malloc(sizeof(tree));
    root->number_of_nodes = 0;
    for (int i = 0; i < MAX_TREE_SIZE; i++) {
        root->nodes[i] = init_node(i);
    }
    return root;
}

void create_tree(tree *root, int size, node *input[]) {
    for (int i = 0; i < size; i++) {
        root->nodes[input[i]->state_number]->value = input[i]->value;
        root->nodes[input[i]->state_number]->parent = input[i]->parent;
        if (input[i]->parent == -1) {
            input[i]->parent = 0;
        }
        root->nodes[input[i]->parent]->children[root->nodes[input[i]->parent]->number_of_children++] = root->nodes[input[i]->state_number];
        root->number_of_nodes++;
    }
}

void print_tree(tree *root) {
    printf("Number of nodes: %d\n\n", root->number_of_nodes);
    for (int i = 0; i <= root->number_of_nodes; i++) {
        printf("name: %d\n", root->nodes[i]->state_number);
        printf("value: %d\n", root->nodes[i]->value);
        printf("parent: %d\n", root->nodes[i]->parent);
        printf("number of children: %d\n", root->nodes[i]->number_of_children);
        printf("children: ");
        for (int j = 0; j < root->nodes[i]->number_of_children; j++) {
            printf("%d ", root->nodes[i]->children[j]->state_number);
        }
        printf("\n\n");
    }
}