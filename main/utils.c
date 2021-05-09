#include "utils.h"

void main_input()
{
    input = (node *)calloc(size, sizeof(node));
    for (int i = 0; i < size; i++)
    {
        scanf("%d%d%d", &(input[i].state_number), &(input[i].value), &(input[i].parent));
    }
}

/*    Tree Traveral:
    - Push the root node into the PQueue
    - Pop the top-most element
    - Push its children into the PQueue */
void traverse()
{
    PQ = init_pq();
    output = (node *)calloc(size, sizeof(node));
    seen_time = 0;

    T->nodes[1]->seen_time = seen_time++;
    T->nodes[1]->depth = 0;
    insert_node(PQ, T->nodes[1]);

    int j = 0;
    while (PQ->size > 0)
    {
        node *top = pop(PQ);
        for (int i = 0; i < top->number_of_children; i++)
        {
            top->children[i]->seen_time = seen_time++;
            top->children[i]->depth = top->depth + 1;
            insert_node(PQ, top->children[i]);
        }
        output[j++] = *top;
    }

    // Free PQueue
    destroy_pq(PQ);
}

void print_traversal()
{
    printf("sno.\tvalue\tparent\tseen_time\tdepth\n");

    for (int i = 0; i < size; i++)
    {
        printf("%d\t%d\t%d\t%d\t%d\n", output[i].state_number, output[i].value, output[i].parent, output[i].seen_time, output[i].depth);
    }
}

void stats()
{
    max_depth = (int *)calloc(size, sizeof(int));
    avg_depth = (double *)calloc(size, sizeof(double));
    visited = (int *)calloc(size, sizeof(int));
    max_child = (int *)calloc(size, sizeof(int));

    avg_depth[0] = output[0].depth;
    max_depth[0] = output[0].depth;
    for (int i = 1; i < size; i++)
    {
        avg_depth[i] = (avg_depth[i - 1] * i + output[i].depth) / (i + 1);
        max_depth[i] = output[i].depth > max_depth[i - 1] ? output[i].depth : max_depth[i - 1];

        int parent = output[i].parent;
        if (parent == -1)
            parent = 0;
        visited[parent]++;
        max_child[i] = visited[parent] > max_child[i - 1] ? visited[parent] : max_child[i - 1];
    }
}

void print_stats()
{
    FILE *fptr = fopen("./stats/out.csv", "w");

    fprintf(fptr, "n,Max Depth,Avg Depth,Max_Children\n");
    for (int i = 0; i < size; i++)
    {
        fprintf(fptr, "%d,%d,%lf,%d\n", i + 1, max_depth[i], avg_depth[i], max_child[i]);
    }

    fclose(fptr);

    free(max_depth);
    free(avg_depth);
    free(visited);
    free(max_child);
}