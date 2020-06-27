#include <stdio.h>
#include <setjmp.h>

jmp_buf j;

void error_recovery (void);

int main (void) {
    int i = setjmp(j);
    if (!i) {
        printf("First iteration\n");
        error_recovery();
    } else {
        printf("Error code %d\n", i);
    }
}

void error_recovery (void) {
    longjmp(j, 1);
}
