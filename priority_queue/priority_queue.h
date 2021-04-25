#ifndef _PRIORITY_QUEUE_H_
#define _PRIORITY_QUEUE_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define file_read freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
#define MAX_SIZE 10000

typedef struct priority_queue {
    int size;
    int arr[MAX_SIZE];
} pq;

int compare(int *a, int *b);                        // Compare Function
void swap(int *a, int *b);                          // Swapping Fucntion
pq *create_pq();                                    // Creates and initialilzes the priority queue with size 0 and all elements -1
void input_pq(pq *head, int size, int *input_arr);  // Takes input array and inserts into the pq
void insert_node(pq *head, int val);                // Inserts a node into the pq
void sift_up(pq *head, int id);                     // Sifts up the node at id to appropriate priority
void sift_down(pq* head, int id);                   // Sifts down the node at id to appropriate priority
int peek(pq *head);                                 // Returns the top element (i.e highest priority element)
int pop(pq *head);                                  // Deletes the top element and returns it

#endif