#include "circular_array.h"


struct circular_array {
    data_type* items;
    int capacity;
    int size;
    int front;
    int rear;
    bool dynamic;
};

CircularArray* circular_array_construct(int capacity, bool dynamic) {
    CircularArray* circular_array = malloc(sizeof(CircularArray));

    circular_array->capacity = capacity;
    circular_array->size = 0;
    circular_array->front = 0;
    circular_array->rear = -1;
    circular_array->dynamic = dynamic;
    circular_array->items = malloc(sizeof(data_type) * capacity);

    return circular_array;
}