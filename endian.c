#include <stdio.h>
#include <limits.h>

int main (void) {
    unsigned int val = 62;
    char* str = (char*) &val;
    for (int i = 0; i < sizeof(int); i++) {
        printf("%u ", str[i]);
    }
    putchar('\n');
}
