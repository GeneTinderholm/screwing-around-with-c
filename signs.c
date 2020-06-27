#include <stdio.h>

int main (void) {
    int i = 5;
    int j = ~i;
    int k = j + 1;

    printf("one's compliment: %d\n", j);
    printf("two's compliment: %d\n", k);
}
