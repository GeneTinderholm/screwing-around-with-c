// need to link pthread (-l pthread)
#include <stdio.h>
#include <pthread.h>

void* hello_thread() {
    printf("Hello, Thread!\n");
    return NULL;
}

int main (void) {
    pthread_t threads[10];
    for (int i = 0; i < 10; ++i) {
        pthread_create(&threads[i], NULL, hello_thread, NULL);
    }

    for (int i = 0; i < 10; ++i) {
        pthread_join(threads[i], NULL);
    }
    return 0;
}
