#ifndef _UTILS_H_
#define _UTILS_H_

#include "../tree/tree.h"
#include "../priority_queue/priority_queue.h"

// Global variables

int size;     // Input size
node *input;  // Input Array
node *output; // Output Array

tree *T; // Tree
pq *PQ;  // PQueue

// Traversal Parameters
int seen_time;

void main_input(); // Taking input

void traverse();        // Tranverse the tree given the mode and store in output array
void print_traversal(); // Print the output array

// Stats Arrays
int *max_depth;
double *avg_depth;
int *visited;
int *max_child;

void stats();       // Store the statistics in global arrays
void print_stats(); // Prints the stats to "./stats/out.csv"

#endif
