#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <pthread.h>
#include <unistd.h>

#define NUM_THREADS 10
pthread_mutex_t mutex;
int i = 0;

void* work_that_requires_mutex(void* thread_num);

int main (void) {
    // PTHREAD_MUTEX_INITIALIZER also available
    pthread_mutex_init(&mutex, NULL);

    pthread_t threads[NUM_THREADS];
    int thread_nums[NUM_THREADS];

    printf("i is 0\n");
    for (int i = 0; i < NUM_THREADS; ++i) {
        thread_nums[i] = i + 1;
        pthread_create(&threads[i], NULL, work_that_requires_mutex, &thread_nums[i]); 
    }

    for (int i = 0; i < NUM_THREADS; ++i) {
        pthread_join(threads[i], NULL); 
    }
    printf("i is %d\n", i);

    pthread_mutex_destroy(&mutex);
}

void* work_that_requires_mutex(void* thread_num) {
    int tnum = *(int*) thread_num;

    srand(time(0));
    sleep(rand() % 10);
    int rand_num = rand() % 10;

    pthread_mutex_lock(&mutex);
    printf("Thread %d found i as %d, adding %d\n", tnum, i, rand_num);
    i += rand_num;
    pthread_mutex_unlock(&mutex);

    return NULL;
}
