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

bool circular_array_is_empty(CircularArray* circular_array) {
    // Verifica se o tamanho é igual a zero
    if (circular_array->size == 0) {
        // Se o tamanho for zero, o array está vazio
        return true;
    } else {
        // Caso contrário, o array não está vazio
        return false;
    }
}

bool circular_array_is_full(CircularArray* circular_array) {
    // Calcula o próximo índice rear considerando a capacidade
    int next_rear = (circular_array->rear + 1) % circular_array->capacity;

    // Verifica se o próximo índice rear é igual ao índice front
    if (next_rear == circular_array->front) {
        // Se forem iguais, significa que o CircularArray está cheio
        return true;
    } else {
        // Caso contrário, o CircularArray não está cheio
        return false;
    }
}
