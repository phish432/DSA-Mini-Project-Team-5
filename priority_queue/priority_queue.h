#ifndef _PRIORITY_QUEUE_H_
#define _PRIORITY_QUEUE_H_

#include "../node/node.h"

#define MAX_PQ_SIZE 1000

typedef struct priority_queue pq;

struct priority_queue {
    int size;
    node *arr[MAX_PQ_SIZE];
};

pq *init_pq();
void input_pq(pq *head, int size, node *input[]);
void insert_node(pq *head, node *val);

void sift_up(pq *head, int id);
void sift_down(pq *head, int id);

node *peek(pq *head);
node *pop(pq *head);

#endif