#include <stdio.h>

int main (void) {
    int x = 42;
    int* px = &x;

    printf("address of px: %p\n", &px);
    printf("value of px:   %p\n", px);
    printf("value of x:    %d\n", *px);
}
