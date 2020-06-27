#include <stdio.h>
#include <stdlib.h>

void allocate_mem(int** x);
int main (void) {
    int x = 50;
    int* y = &x;
    int** z = &y;
    printf("  x = %d\n", x);
    printf(" *y = %d\n", *y);
    printf("**z = %d\n", **z);

    printf(" &x = %p\n", &x);
    printf("  y = %p\n", y);
    printf(" *z = %p\n", *z);

    printf(" &y = %p\n", &y);
    printf("  z = %p\n", z);

    int *a = NULL;
    allocate_mem(&a);
    *a = 4;
    printf(" *a = %d\n", *a);
}

void allocate_mem(int** x) {
    *x = malloc(sizeof(int));
}
