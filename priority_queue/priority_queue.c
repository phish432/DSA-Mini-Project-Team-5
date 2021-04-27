#include "priority_queue.h"

int compare(int *a, int *b) {
    int x = *a;
    int y = *b;
    // returns 1 if a has higher priority than b
    // priority depends on use-case
    if (x < y)  return 1;
    return 0;
}

void swap(int *a, int *b) {
    int *c = (int *)malloc(sizeof(int));
    memcpy(c, a, sizeof(int));
    memcpy(a, b, sizeof(int));
    memcpy(b, c, sizeof(int));
}

pq *create_pq() {
    pq *a = (pq *)malloc(sizeof(pq));
    a->size = 0;
    for (int i = 0; i < MAX_SIZE; i++) {
        a->arr[i] = -1;
    }
    return a;
}

void input_pq(pq *head, int size, int *input_arr) {
    for (int i = 0; i < size; i++) {
        insert_node(head, input_arr[i]);
    }
}

void insert_node(pq *head, int val) {
    // Inserts at end of pq then sifts up
    head->arr[head->size] = val;
    sift_up(head, head->size);
    head->size++;
}

void sift_up(pq *head, int id) {
    int parent = (id - 1) / 2;
    while (parent >= 0) {
        // If child has higher priority than parent then swap
        if (compare(&(head->arr[id]), &(head->arr[parent])) == 1) {
            swap(&(head->arr[id]), &(head->arr[parent]));
            
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
        // Check if right child exits and if it has higher priority than left child
        if (j + 1 < n && compare(&(head->arr[j + 1]), &(head->arr[j])) == 1) j++;

        // If parent already has higher priority than child return
        if (compare(&(head->arr[id]), &(head->arr[j]))) return;
        
        // Else swap
        swap(&(head->arr[id]), &(head->arr[j]));
        id = j;
        j = 2 * id + 1;
    }
}

int peek(pq *head) {
    if (head->size == 0) return -1;
    return head->arr[0];
}

int pop(pq *heap) {
    int ret_val = -1;
    if (heap->size > 0) {
        swap(&(heap->arr[0]), &(heap->arr[heap->size - 1]));
        heap->size--;
        
        sift_down(heap, 0);
        
        ret_val = heap->arr[heap->size];
        heap->arr[heap->size] = -1;
    }
    return ret_val;
}