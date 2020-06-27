/* #include "celc.h" */
#include <stdio.h>

int main() {
    float celsius, fahr;
    int lower, upper, step;

    lower = 0;
    upper = 300;
    step = 20;

    celsius = lower;
    printf(" C  |  F\n");
    printf("----------\n");
    while (celsius <= upper) {
        // fahr - 32 = (cels * 5) / 9 + 32
        fahr = celsius * 9.0 / 5.0 + 32.0;
        printf("%3.0f %6.1f\n", celsius, fahr);
        celsius += step;
    }
}
