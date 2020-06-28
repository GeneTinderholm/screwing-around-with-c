#include <stdio.h>
#include "string_functions.h"

int main (void) {
    char* catted = str_cat("Hello, ", "World!");
    puts(catted);
    char* search = "This is a string to search in.";
    puts(search);
    printf("%c appears %d times.\n", 's', char_freq(search, 's'));
    char* len_test = "This is a test string.";
    printf("%s is %d characters long.\n", len_test, str_len(len_test));
    puts(strip_string("Th80392is*$Sh320ou2ld8B3eR1 2`ead3a`ble"));
}
