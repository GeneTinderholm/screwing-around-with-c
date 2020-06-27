#include <stdio.h>

int gcd (int a, int b) {
    if (a == 0) return b;

    return gcd(b % a, a);
}

float absolute_value (float a) {
    if (a < 0) return -a;
    return a;
}

float sqrt_help(float a, float b) {
    float precision = .01;
    float sqr_b = b * b;
    if (absolute_value(a - sqr_b) < precision) {
        return b;
    }
    return sqrt_help(a, (a / b + b) / 2);
}

float square_root (float a) {
    if (absolute_value(a) != a) {
        printf("negative numbers invalid for square_root\n");
        return -1.0;
    }
    return sqrt_help(a, a / 2);
}

int main (void) {
    printf("%d\n", gcd(2166, 6099));
    /* printf("%d\n", gcd(9, 2)); */
    /* printf("%d\n", gcd(160, 32)); */
    /* printf("%d\n", (int) absolute_value(4)); */
    /* printf("%d\n", (int) absolute_value(-4)); */
    /* printf("%f\n", absolute_value(4.2)); */
    /* printf("%f\n", absolute_value(-4.2)); */
    /* printf("%f\n", square_root(0)); */
    /* printf("%f\n", square_root(1)); */
    /* printf("%f\n", square_root(150)); */
    /* printf("%f\n", square_root(.25)); */
    /* printf("%f\n", square_root(.3)); */
    /* printf("%f\n", square_root(-4)); */
}
