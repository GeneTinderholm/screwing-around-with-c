#include <stdio.h>

int check_bit (int num, int bit);
void set_bit (int* num, int bit);
int main (void) {
    printf("Enter an integer: ");
    int num;
    scanf("%d", &num);
    printf("Enter a bit position (0-31): ");
    int bit;
    scanf("%d", &bit);
    printf("The bit was%sset!\n", check_bit(num, bit) ? " " : " not ");
    printf("Number before setting the bit: %d\n", num);
    set_bit(&num, bit);
    printf("Number after setting the bit:  %d\n", num);
}

int check_bit (int num, int bit) {
    int mask = 1 << bit;

    if (num & mask)
        return 1;

    return 0;
}

void set_bit (int* num, int bit) {
    int mask = 1 << bit;
    *num |= mask;
}
