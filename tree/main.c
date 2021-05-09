#include "tree.h"

int main(void) {
    int size;
    scanf("%d", &size);

    node *input[size];
    for (int i = 0; i < size; i++) {
        input[i] = (node *)malloc(sizeof(node));
    }

    for (int i = 0; i < size; i++) {
        scanf("%d%d%d", &(input[i]->state_number), &(input[i]->value), &(input[i]->parent));
    }

    tree *T = init_tree();
    create_tree(T, size, input);

    print_tree(T);

    return 0;
}