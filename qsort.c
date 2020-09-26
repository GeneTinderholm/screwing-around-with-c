#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void print_arr(double* arr, int length);
int compare_double_arr(const void* a, const void* b);
void fill_arr(double* arr, int length);

int main (void) {
    int size = 5;
    double arr[size];
    fill_arr(arr, size);

    printf("Unsorted: ");
    print_arr(arr, size);

    qsort(arr, 5, sizeof(double), compare_double_arr);

    printf("Sorted:   ");
    print_arr(arr, size);
}

int compare_double_arr(const void* a, const void* b) {
    double first = *(double*)a;
    double second = *(double*)b;

    return first - second;
}

void print_arr(double* arr, int length) {
    printf("[");
    for (int i = 0; i < length; ++i) {
        printf(" %1.3f", arr[i]);

        if (i != length - 1) {
            printf(",");
        }
    }
    printf(" ]\n");
}

void fill_arr(double* arr, int length) {
    srand(time(0));

    for (int i = 0; i < length; ++i) {
        arr[i] = (double) (rand() % 10000) / 1000;
    }
}
