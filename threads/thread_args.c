#include <stdio.h>
#include <pthread.h>

void* print_message(void* arg);

int main (void) {
    int indexes[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    pthread_t threads[10];

    printf("In main thread.\n");

    for (int i = 0; i < 10; ++i) {
        pthread_create(&threads[i], NULL, print_message, &indexes[i]);
    }
    for (int i = 0; i < 10; ++i) {
        pthread_join(threads[i], NULL);
    }
}

void* print_message(void* arg) {
    int* thread_number = (int*) arg;

    printf("In thread %d.\n", *thread_number);

    return NULL;
}
