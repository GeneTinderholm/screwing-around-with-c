#include <stdio.h>

int main (void) {
    int x = 4;
    int y = 5;

    x ^= y;
    y ^= x;
    x ^= y;

    printf("x: %d\n", x);
    printf("y: %d\n", y);
}
