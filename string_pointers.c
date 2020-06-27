#include <stdio.h>

int string_length (const char* x) {
    const char* px = x;

    while (*px) ++px;

    return px - x;
}

int main (void) {
    char* x = "test string";
    int len = string_length(x);
    printf("%d\n", len);
    printf("%d\n", string_length("abcde"));
}
