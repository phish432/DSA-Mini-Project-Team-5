#include "node.h"

/*	Comparator:
	The comparator picks the suitable comparison parameter based on the global flag variable.
	Returns true if the 1st node has a higher priority than the 2nd node
	For DFS, we pick higher seen time
	For BFS, we pick smaller seen time
	For Greedy, we pick higher stored value	*/
bool node_comparator(node *a, node *b)
{
	node x = *a;
	node y = *b;

	bool ret = false;

	if (strcmp(flag, "dfs") == 0) {
		if (x.seen_time > y.seen_time)  ret = true;
	}
	else if (strcmp(flag, "bfs") == 0) {
		if (x.seen_time < y.seen_time)  ret = true;
	}
	else if (strcmp(flag, "greedy") == 0) {
		if (x.value > y.value)  ret = true;
	}

	return ret;
}

void swap(node *a, node *b)
{
	node *c = (node *)malloc(sizeof(node));
	memcpy(c, a, sizeof(node));
	memcpy(a, b, sizeof(node));
	memcpy(b, c, sizeof(node));
	free(c);
}

node *init_node(int index)
{
	node *ptr = (node *)malloc(sizeof(node));

	ptr->state_number = index;
	ptr->value = -1;
	ptr->parent = -1;
	ptr->number_of_children = 0;
	for (int i = 0; i < MAX_CHILDREN; i++) {
		ptr->children[i] = NULL;
	}
	ptr->seen_time = 0;
	ptr->depth = 0;

	return ptr;
}