#include <stdio.h>

void square (int* x) {
    *x *= *x;
}

int main (void) {
    int x = 42;

    square(&x);

    printf("%d\n", x);
}
