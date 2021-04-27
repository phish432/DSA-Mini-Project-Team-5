#include "priority_queue.h"

pq *init_pq() {
    pq *head = (pq *)malloc(sizeof(pq));
    head->size = 0;
    for (int i = 0; i < MAX_PQ_SIZE; i++) {
        head->arr[i] = init_node(i);
    }
    return head;
}

void input_pq(pq *head, int size, node *input[]) {
    for (int i = 0; i < size; i++) {
        insert_node(head, input[i]);
    }
}

void insert_node(pq *head, node *val) {
    *(head->arr[head->size]) = *val;
    sift_up(head, head->size);
    head->size++;
}

void sift_up(pq *head, int id) {
    int parent = (id - 1) / 2;
    while (parent >= 0) {
        if (node_comparator(head->arr[id], head->arr[parent])) {
            swap(head->arr[id], head->arr[parent]);
            id = parent;
            parent = (id - 1) / 2;
        }
        else return;
    }
}

void sift_down(pq *head, int id) {
    int n = head->size;
    int j = 2 * id + 1;
    while (j < n) {
        if (j + 1 < n && node_comparator(head->arr[j + 1], head->arr[j])) j++;
        if (node_comparator(head->arr[id], head->arr[j])) return;
        swap(head->arr[id], head->arr[j]);
        id = j;
        j = 2 * id + 1;
    }
}

node *peek(pq *head) {
    if (head->size == 0) return NULL;
    return head->arr[0];
}

node *pop(pq *heap) {
    node *ret_val = NULL;
    if (heap->size > 0) {
        swap(heap->arr[0], heap->arr[heap->size - 1]);
        heap->size--;

        sift_down(heap, 0);

        ret_val = heap->arr[heap->size];
        heap->arr[heap->size] = NULL;
    }
    return ret_val;
}