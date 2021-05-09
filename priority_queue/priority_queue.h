#ifndef _PRIORITY_QUEUE_H_
#define _PRIORITY_QUEUE_H_

#include "../node/node.h"

#define MAX_PQ_SIZE 100005

typedef struct priority_queue pq;

struct priority_queue {
	int size;
	node *heap[MAX_PQ_SIZE];
};

pq *init_pq();	// Initializes priority queue
void input_pq(pq *PQ, int size, node *input[]);	// Takes an input array and adds to priority queue
void insert_node(pq *PQ, node *val);				// Inserts a node into the priority queue

void sift_up(pq *PQ, int id);		// Sifts up a node to correct place w.r.t. priority
void sift_down(pq *PQ, int id);	// Sifts down a node to correct place w.r.t. priority

node *peek(pq *PQ);	// Returns the highest priority node in the priority queue
node *pop(pq *PQ);	// Deletes the highest priority node

void destroy_pq(pq *PQ);

#endif