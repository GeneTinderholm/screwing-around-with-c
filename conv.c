#include <stdio.h>

int bin_to_int (long long bin);
long long int_to_bin (int i);
int main (void) {
    printf("Enter binary number to be converted: ");
    long long bin;
    scanf("%lld", &bin);
    printf("As an int: %d\n", bin_to_int(bin));
    printf("Enter int to be converted: ");
    int i;
    scanf("%d", &i);
    printf("As binary: %lld\n", int_to_bin(i));
}

int bin_to_int (long long bin) {
    int bin_pow = 1,
        int_pow = 1,
        res = 0;

    while (bin > 0) {
        if (bin % (10 * int_pow) != 0) {
            bin -= int_pow;
            res += bin_pow;
        }
        bin_pow *= 2;
        int_pow *= 10;
    }
    return res;
}

long long int_to_bin (int i) {
    int bin_pow = 1,
        int_pow = 1,
        res = 0;

    while (i > 0) {
        if (i % (2 * bin_pow) != 0) {
            i -= bin_pow;
            res += int_pow;
        }
        bin_pow *= 2;
        int_pow *= 10;
    }

    return res;
}
