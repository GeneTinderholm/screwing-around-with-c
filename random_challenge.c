#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main (void) {
    // generating 50 random numbers from -.5 to .5
    srand(time(0));

    for (int i = 0; i < 50; ++i) {
        int r = rand() % 1000;
        float big_rand = (float) r / 1000;
        float final = big_rand - .5;
        printf("%f\n", final);
    }
}
