#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

void* print_message(void* arg);

#define NUM_THREADS 10

int main (void) {
    int indexes[NUM_THREADS] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    pthread_t threads[NUM_THREADS];
    int* ret_vals[NUM_THREADS];

    printf("In main thread.\n");

    for (int i = 0; i < NUM_THREADS; ++i) {
        pthread_create(&threads[i], NULL, print_message, &indexes[i]);
    }
    for (int i = 0; i < NUM_THREADS; ++i) {
        pthread_join(threads[i], (void**) &ret_vals[i]);
    }

    for (int i = 0; i < NUM_THREADS; ++i) {
        printf("Thread %2d returned %d\n", i + 1, *ret_vals[i]);
        free(ret_vals[i]);
    }
}

void* print_message(void* arg) {
    int* thread_number = (int*) arg;
    int* ret_val = malloc(sizeof(int));

    *ret_val = 10 - *thread_number;

    printf("In thread %2d, returning %d.\n", *thread_number, *ret_val);

    return ret_val;
}
