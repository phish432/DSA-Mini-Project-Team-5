#include "priority_queue.h"

pq *init_pq()
{
	pq *PQ = (pq *)malloc(sizeof(pq));

	PQ->size = 0;
	for (int i = 0; i < MAX_PQ_SIZE; i++) {
		PQ->heap[i] = init_node(i);
	}

	return PQ;
}

void input_pq(pq *PQ, int size, node *input[])
{
	for (int i = 0; i < size; i++) {
		insert_node(PQ, input[i]);
	}
}

/*	Insert node in PQueue:
	- Insert the node at the end of pqueue
	- Sift the node up to correct position
	- Update the size of pqueue */
void insert_node(pq *PQ, node *val)
{
	PQ->heap[PQ->size] = val;
	sift_up(PQ, PQ->size);
	PQ->size++;
}

/*	Sift Up:
	- Keep swapping the node with its parent
	  till we either reach the root node or
	  we reach a parent with higher priority */
void sift_up(pq *PQ, int id)
{
	int parent = (id - 1) / 2;

	while (parent >= 0) {
		if (node_comparator(PQ->heap[id], PQ->heap[parent])) {
			swap(PQ->heap[id], PQ->heap[parent]);
			id = parent;
			parent = (id - 1) / 2;
		}
		else return;
	}
}

/*	Sift Down:
	- Keep swapping the node with its children
	  till we either reach the last node or we reach a child with lower priority
	- Select the child with higher priority
	- If node already has higher priority than either child then return
	- Else swap with higher priority child */
void sift_down(pq *PQ, int id)
{
	int last = PQ->size;
	int child = 2 * id + 1;	// Left child

	while (child < last) {
		if (child + 1 < last && node_comparator(PQ->heap[child + 1], PQ->heap[child])) child++;

		if (node_comparator(PQ->heap[id], PQ->heap[child])) return;

		swap(PQ->heap[id], PQ->heap[child]);
		id = child;
		child = 2 * id + 1;
	}
}

/*	Peek:
	- If pqueue empty, we return NULL
	- Else return the top-most node */
node *peek(pq *PQ)
{
	if (PQ->size == 0) return NULL;
	return PQ->heap[0];
}

/*	Pop:
	- If the pqueue is empty we return NULL
	- Swap first and last element in pqueue
	- Decreasing the PQ size by 1 makes the last node deleted
	- Sift down the new top element to regain PQ property */
node *pop(pq *PQ)
{

	node *ret_val = NULL;

	if (PQ->size > 0) {

		swap(PQ->heap[0], PQ->heap[PQ->size - 1]);
		PQ->size--;

		sift_down(PQ, 0);

		ret_val = PQ->heap[PQ->size];
		PQ->heap[PQ->size] = NULL;
	}

	return ret_val;
}

void destroy_pq(pq *PQ)
{
	for (int i = 0; i < MAX_PQ_SIZE; i++) {
		free(PQ->heap[i]);
	}
	free(PQ);
}