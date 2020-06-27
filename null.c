#include <stdio.h>

int main (void) {
    int* p = NULL;
    char c = '\0';
    long null_as_long = (long) p;

    printf("%d\n", ((long) c == null_as_long));
}
