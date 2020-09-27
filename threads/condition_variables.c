#include <unistd.h>
#include <stdio.h>
#include <pthread.h>

#define NUM_THREADS 10

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t cond = PTHREAD_COND_INITIALIZER;

void* thread_stuff(void*);
void* orchestrate();
int count = 0;

int main (void) {
    pthread_t orchestrator;
    pthread_t threads[NUM_THREADS];
    int indexes[NUM_THREADS];

    for (int i = 0; i < NUM_THREADS; ++i) {
        indexes[i] = i + 1;
        pthread_create(&threads[i], NULL, thread_stuff, &indexes[i]);
    }

    pthread_create(&orchestrator, NULL, orchestrate, NULL);

    pthread_join(orchestrator, NULL);
}

void* thread_stuff(void* arg) {
    int thread_num = *(int*) arg;

    pthread_mutex_lock(&mutex);

    // odd numbered threads run last
    if (thread_num % 2 == 1) {
        while (count < 5) {
            pthread_cond_wait(&cond, &mutex);
        }
    }
    printf("Thread %2d running. Found count as %d. Incrementing to %d.\n", thread_num, count, count + 1);

    ++count;

    // previous implementation, theoretically if a thread wasn't waiting before all other threads has finished, it would never finish.
    // using a separate thread to coordinate to make sure everything works every time
    /* if (count >= 5) { */
    /*     pthread_cond_signal(&cond); */
    /*     // pthread_cond_broadcast(&cond); // also works here */
    /* } */

    pthread_mutex_unlock(&mutex);

    return NULL;
}

void* orchestrate() {
    while (count < 5) {
        usleep(100 * 1000);
    }
    while (count < 10) {
        pthread_cond_signal(&cond);
        usleep(100 * 1000);
    }
    return NULL;
}
