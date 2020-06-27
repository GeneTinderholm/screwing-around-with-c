#include <stdio.h>
#include <stdlib.h>
#define arr_len(array_to_get_length_of) (sizeof(array_to_get_length_of) / sizeof(array_to_get_length_of[0]))

typedef struct {
    int* arr;
    int length;
} Arr;

Arr* arr_init(int* arr, int length) {
    Arr* array = malloc(sizeof(Arr));
    array->arr = arr;
    array->length = length;

    return array;
}

int merge_sort(Arr* arr) {
    
    return arr->length;
}

int main() {
    int x[] = {1, 2, 3, 4, 5};
    Arr* arr = arr_init(x, arr_len(x));

    printf("%d\n", merge_sort(arr));
    free(arr);
}
