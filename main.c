#include <stdio.h>
#include <stdbool.h>
#include "circular_array.h"

void print_int(int value) {
    printf("%d", value);
}

int main() {
    CircularArray* array = circular_array_construct(5, true);

    circular_array_push(array, 1);
    circular_array_push(array, 2);
    circular_array_push(array, 3);
    circular_array_push(array, 4);
    circular_array_push(array, 5);

    circular_array_print(array, print_int);

    int popped_value = circular_array_pop(array);
    printf("Popped value: %d\n", popped_value);

    circular_array_print(array, print_int);

    circular_array_destruct(array);

    return 0;
}
