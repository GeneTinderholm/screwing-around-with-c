#include <stdio.h>

union test_union {
    int x;
    float y;
};

int main (void) {
    union test_union z;

    z.y = 4.0;

    printf("%d\n", z.x);
}
