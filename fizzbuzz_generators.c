#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* fizzes();
char* buzzes();
char* fizzbuzzes();
char* fizzbuzz(unsigned int n);
char* number_to_string(unsigned int n);

int main (void) {
    for (int i = 1; i <= 100; ++i)
        printf("%s\n", fizzbuzz(i));
}

char* fizzbuzz(unsigned int n) {
    char* result = fizzbuzzes();

    if(strlen(result))
        return result;

    return number_to_string(n);
}

char* fizzbuzzes() {
    char* fizz = fizzes();
    char* buzz = buzzes();
    int length = strlen(fizz) + strlen(buzz);
    char* result = malloc(length + 1);
    strcat(result, fizz);
    strcat(result, buzz);

    return result;
}

char* fizzes() {
    static int i = 0;
    ++i;
    if (i == 3) {
        i = 0;
        return "FIZZ";
    }
    return "";
}

char* buzzes() {
    static int i = 0;
    ++i;
    if (i == 5) {
        i = 0;
        return "BUZZ";
    }
    return "";
}

char* number_to_string(unsigned int n) {
    if (n == 0)  // might be able to do a do/while loop instead
        return "0";

    int length = 0; 
    int current = n;

    while (current > 0) {
        ++length;
        current /= 10;
    }

    char* result = malloc(sizeof(char) * (length + 1)); // for null terminator

    current = n;
    for (int i = 1; i <= length; ++i) {
        result[length - i] = '0' + (current % 10);
        current /= 10;
    }
    result[length] = '\0';

    return result;
}
