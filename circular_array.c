#include "circular_array.h"


struct circular_array {
    data_type* items;
    int capacity;
    int size;
    int front;
    int rear;
    bool dynamic;
};
