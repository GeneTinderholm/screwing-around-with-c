#include <stdio.h>
#include <pthread.h>

pthread_attr_t attr;

void* display_stack_size() {
    size_t stack_size;
    pthread_attr_getstacksize(&attr, &stack_size);

    printf("Thread stack size: %li.\n", stack_size);
    return NULL;
}

int main (void) {
    size_t default_size;
    pthread_attr_init(&attr);
    pthread_attr_getstacksize(&attr, &default_size);

    printf("Default stack size: %li.\n", default_size);
    size_t new_stack_size = 1 << 16;
    pthread_attr_setstacksize(&attr, new_stack_size);
    pthread_t thread;
    pthread_create(&thread, &attr, display_stack_size, NULL);
    pthread_join(thread, NULL);
}
