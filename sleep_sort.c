#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

#define ARR_LEN 20

void* sleep_n_print(void* num);
void sleepsort(int count, int* nums);

int main (void) {
    srand(time(0));
    int nums[ARR_LEN] = {0};
    printf("unsorted: ");
    for (int i = 0; i < ARR_LEN; ++i) {
        nums[i] = rand() % 25 + 1;
        printf("%d ", nums[i]);
    }
    putchar('\n');
    printf("sorted:   ");
    fflush(stdout);
    sleepsort(ARR_LEN, nums);

    return 0;
}

void sleepsort(int count, int* nums) {
    pthread_t threads[ARR_LEN];
    for (int i = 0; i < ARR_LEN; ++i) {
        pthread_create(&threads[i], NULL, sleep_n_print, &nums[i]);
    }
    for (int i = 0; i < ARR_LEN; ++i) {
        pthread_join(threads[i], NULL);
    }
    putchar('\n');
}

void* sleep_n_print(void* num) {
    int n = *(int*)num;
    /* usleep(n * 1000); */ // also works, depends on your machine speed
    sleep(n);               // technically also depends on machine speed, but should work on anything made after 1960 or so
    printf("%d ", n);
    fflush(stdout);

    return NULL;
}
