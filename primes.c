#include <stdio.h>

int main (void) {
    int primes[100] = {2, 3};
    int curr_index = 2;

    for (int i = 5; i < 100; i += 2) {
        _Bool prime = 1;
        for (int j = 1; i / primes[j] >= primes[j]; ++j) 
            if (i % primes[j] == 0) 
                prime = 0;
        if (prime) primes[curr_index++] = i;
    }

    for (int i = 0; i < curr_index; ++i) printf("%2d ", primes[i]);
    putchar('\n');
    printf("   ");
    for (int i = 1; i < curr_index; ++i) printf("%2d ", primes[i] - primes [i - 1]);
    putchar('\n');
}
