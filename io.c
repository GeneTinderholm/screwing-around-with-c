/* #include "io.h" */
#include <stdio.h>

int main() {
    int car;

    while ((car = getchar()) != EOF) {
        if (car == '\t') {
            printf("\\t");
        } else if (car == '\b') {
            printf("\\b");
        } else if (car == '\\') {
            printf("\\\\");
        } else {
            putchar(car);
        }
    }
}
