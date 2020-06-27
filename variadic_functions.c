#include <stdio.h>
#include <stdarg.h>

double average(int argc, ...);
int sum(int argc, ...);

int main (void) {
    int x = sum(5, 1, 2, 3, 4, 5);
    double y = average(5, 1.0, 2.0, 3.0, 4.0, 5.0);

    printf("Sum is %d\n", x);
    printf("Average is %f\n", y);
}

int sum (int argc, ...) {
    va_list parg;
    va_start(parg, argc);

    int total = 0;

    for (int i = 0; i < argc; ++i) {
        total += va_arg(parg, int);
    }

    va_end(parg);

    return total;
}

double average (int argc, ...) {
    va_list parg;
    va_start(parg, argc);

    double total = 0;

    for (int i = 0; i < argc; ++i) {
        total += va_arg(parg, double);
    }

    va_end(parg);

    printf("%f\n", total);
    printf("%d\n", argc);

    return total / argc;
}
