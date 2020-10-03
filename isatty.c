#include <stdio.h>
#include <unistd.h>

#define STDIN 0

int main(void) {
    printf("%d\n", isatty(STDIN));
}
