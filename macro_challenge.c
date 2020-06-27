#include <stdio.h>

#define SUM(x, y) ((x) + (y))
#define SQUARE(x) ((x) * (x))
#define CUBE(x) ((x) * (x) * (x))

int main (void) {
    printf("Sum 3 and 4: %d\n", SUM(3,4));
    printf("Sum of 3.5 and 6.9: %.1f\n", SUM(3.5, 6.9));
    printf("Square of 8: %d\n", SQUARE(8));
    printf("Cube of 8: %d\n", CUBE(8));
}
