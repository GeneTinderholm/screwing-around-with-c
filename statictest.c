#include <stdio.h>

int sum (int x) {
    static int sum = 0;
    sum += x;
    return sum;
}
int main (void) {
    int x[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int cur = 0;

    for (int i = 0; i < 11; i++) cur = sum(x[i]);

    printf("%d\n", cur);

    return 0;
}
