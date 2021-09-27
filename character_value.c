#include <stdio.h>

int main (int argc, char** argv) {
    char first_char = argv[1][0];
    printf("%c has value %d (0x%x)\n", first_char, first_char, first_char);
}
