#include <stdio.h>

int main (void) {
    int x = 0;
    int* y = &x;

    while (1) {
        printf("%08x", *y++);
    }

    return 0;
}
