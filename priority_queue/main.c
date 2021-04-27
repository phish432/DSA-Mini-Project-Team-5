#include "priority_queue.h"

int main(void) {
    int size;
    scanf("%d", &size);

    node *input[size];
    for (int i = 0; i < size; i++) {
        input[i] = (node *)malloc(sizeof(node));
    }

    for (int i = 0; i < size; i++) {
        scanf("%d%d%d", &(input[i]->state_number), &(input[i]->value), &(input[i]->parent));
    }

    pq *head = init_pq();
    input_pq(head, size, input);

    printf("Heap: ");
    for (int i = 0; i < head->size; i++) {
        printf("%d %d, ", head->arr[i]->state_number, head->arr[i]->value);
    }
    printf("\n");
    printf("size: %d\n\n", head->size);

    node *top = pop(head);
    printf("pop: %d %d\n\n", top->state_number, top->value);

    printf("Heap: ");
    for (int i = 0; i < head->size; i++) {
        printf("%d %d, ", head->arr[i]->state_number, head->arr[i]->value);
    }
    printf("\n");
    printf("size: %d\n", head->size);

    return 0;
}