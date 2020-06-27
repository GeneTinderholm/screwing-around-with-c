#include <stdio.h>
#include "test2.h"

int func (void) {
    int i = 0;

    for (; i <= 0xFFFFFF; ++i);

    return i;
}

int main (void) {
    int x = func();
    printf("x = %d\n", x);
    int y = func_two();
    printf("y = %d\n", y);
}
