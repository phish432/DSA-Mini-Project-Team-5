#include "priority_queue.h"

int main(int argc, char *argv[])
{
    flag = (char *)malloc((strlen(argv[1]) + 1) * sizeof(char));
    strcpy(flag, argv[1]);

    int size;
    scanf("%d", &size);

    node *input[size];
    for (int i = 0; i < size; i++) {
        input[i] = (node *)malloc(sizeof(node));
    }

    for (int i = 0; i < size; i++) {
        scanf("%d%d%d", &(input[i]->state_number), &(input[i]->value), &(input[i]->parent));
    }

    pq *PQ = init_pq();
    input_pq(PQ, size, input);

    printf("Heap: ");
    for (int i = 0; i < PQ->size; i++) {
        printf("%d %d, ", PQ->heap[i]->state_number, PQ->heap[i]->value);
    }
    printf("\n");
    printf("size: %d\n\n", PQ->size);

    node *top = pop(PQ);
    printf("pop: %d %d\n\n", top->state_number, top->value);

    printf("Heap: ");
    for (int i = 0; i < PQ->size; i++) {
        printf("%d %d, ", PQ->heap[i]->state_number, PQ->heap[i]->value);
    }
    printf("\n");
    printf("size: %d\n", PQ->size);

    return 0;
}