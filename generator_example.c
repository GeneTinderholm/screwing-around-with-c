#include <stdio.h>
#include <stdlib.h>

int generator(int (*gen_fun)(int));
int increment(int);
int add_three_and_square(int);

int main (void) {
    generator(increment);

    for (int i = 0; i < 10; ++i) {
        puts("Increment");
        printf("%d\n", generator(NULL));
    }

    generator(add_three_and_square);
    for (int i = 0; i < 4; ++i) {
        puts("Add 3 and square");
        printf("%d\n", generator(NULL));
    }
}

int generator(int (*gen_fun)(int)) {
    static int (*internal_fun)(int) = NULL;
    static int value = 0;

    if (gen_fun == NULL) {
        value = internal_fun(value);
    } else {
        internal_fun = gen_fun;
        value = 0;
    }

    return value;
}

int increment(int n) {
    return n + 1;
}

int add_three_and_square(int n) {
    n += 3;
    return n * n;
}
