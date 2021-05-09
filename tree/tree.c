#include "tree.h"

tree *init_tree()
{
	tree *T = (tree *)malloc(sizeof(tree));

	T->size = 0;
	for (int i = 0; i < MAX_TREE_SIZE; i++) {
		T->nodes[i] = init_node(i);
	}

	return T;
}

// Copy nodes from the input array into the tree
void create_tree(tree *T, int size, node input[])
{
	for (int i = 0; i < size; i++) {
		T->nodes[input[i].state_number]->value = input[i].value;
		T->nodes[input[i].state_number]->parent = input[i].parent;

		// Condition for root node
		if (input[i].parent == -1) {
			input[i].parent = 0;
		}

		// Inserting the given node into the children array of its parent node
		T->nodes[input[i].parent]->children[T->nodes[input[i].parent]->number_of_children++] = T->nodes[input[i].state_number];

		T->size++;
	}
}

void print_tree(tree *T)
{
	printf("Number of nodes: %d\n\n", T->size);

	printf("Name Value Parent NChild Children\n");
	for (int i = 0; i <= T->size; i++) {
		printf("%d ", T->nodes[i]->state_number);
		printf("%d ", T->nodes[i]->value);
		printf("%d ", T->nodes[i]->parent);
		printf("%d ", T->nodes[i]->number_of_children);
		for (int j = 0; j < T->nodes[i]->number_of_children; j++) {
			printf("%d, ", T->nodes[i]->children[j]->state_number);
		}
		printf("\n");
	}
}

void destroy_tree(tree *T)
{
	for (int i = 0; i < MAX_TREE_SIZE; i++) {
		free(T->nodes[i]);
	}
	free(T);
}