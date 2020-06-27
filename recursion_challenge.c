#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// recursively add numbers 1..x
unsigned int recursive_sum(unsigned int x);
unsigned int recursive_gcd(unsigned int a, unsigned int b);
char* reverse_string(char* str);
char* append_chars(char* dest, char* src);
void process_string(char* str);

int main (void) {
    printf("1..5:  %u\n", recursive_sum(5));
    printf("1..10: %u\n", recursive_sum(10));
    printf("gcd(10, 5):   %d\n", recursive_gcd(10, 5));
    printf("gcd(100, 25): %d\n", recursive_gcd(100, 25));
    printf("gcd(158, 36): %d\n", recursive_gcd(158, 36));
    printf("gcd(10, 50): %d\n", recursive_gcd(10, 50));
    process_string("things");
    process_string("stuff");
}

unsigned int recursive_sum (unsigned int x) {
    if (x == 1) return 1;

    return x + recursive_sum(x - 1);
}

unsigned int recursive_gcd (unsigned int a, unsigned int b) {
    if (b == 0) return a;

    return recursive_gcd(b, a % b);
}

void process_string (char* str) {
    printf("The original string is: %s\n", str);
    printf("The reversed string is: %s\n", reverse_string(str));
}

char* reverse_string (char* str) {
    char* dest = malloc(strlen(str) + 1);
    *dest = '\0';

    return append_chars(dest, str);
}

char* append_chars (char* dest, char* src) {
    int dest_len = strlen(dest),
        src_len = strlen(src);

    if (dest_len == src_len) 
        return dest;

    dest[dest_len] = src[src_len - (dest_len + 1)]; // +1 handles null terminator
    dest[dest_len + 1] = '\0';

    return append_chars(dest, src);
}
