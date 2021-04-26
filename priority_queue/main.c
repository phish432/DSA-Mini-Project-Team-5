#include "priority_queue.h"

int main(void) {
    // file_read;
    
    pq *a = create_pq();

    int size;
    scanf("%d", &size);

    int input_arr[size];
    for (int i = 0; i < size; i++) {
        scanf("%d", &input_arr[i]);
    }
    input_pq(a, size, input_arr);
    
    printf("Heap: ");
    for (int i = 0; i < a->size; i++) {
        printf("%d ", a->arr[i]);
    }
    printf("\n");
    printf("size: %d\n", a->size);

    printf("pop: %d\n", pop(a));
    printf("Heap: ");
    for (int i = 0; i < a->size; i++) {
        printf("%d ", a->arr[i]);
    }
    printf("\n");
    printf("size: %d\n", a->size);

    return 0;
}