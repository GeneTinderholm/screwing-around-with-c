#include <assert.h>
#include <stdio.h>

int main (void) {
    int x = 42;

    assert(x == 43);

    printf("All good\n");
    return 0;
}
