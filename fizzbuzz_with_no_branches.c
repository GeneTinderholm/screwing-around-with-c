#include <stdio.h>
#include <stdlib.h>

char* fizzbuzz(unsigned int n);
char* return_fizz(unsigned int n);
char* return_buzz(unsigned int n);
char* return_fizzbuzz(unsigned int n);
char* number_to_string(unsigned int n);

int main (void) {
    for (int i = 1; i <= 100; ++i) {
        printf("%s ", fizzbuzz(i));
    }

    return 0;
}

char* fizzbuzz(unsigned int n) {
    char* (*char_funcs[])(unsigned int) = {
        number_to_string,
        return_fizz,
        return_buzz,
        return_fizzbuzz
    };
    //                0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14
    int indexes[] = { 3, 0, 0, 1, 0, 2, 1, 0, 0, 1,  2,  0,  1,  0,  0 };

    return char_funcs[indexes[n % 15]](n);
}

char* return_fizz(unsigned int n) {
    return "FIZZ";
}
char* return_buzz(unsigned int n) {
    return "BUZZ";
}
char* return_fizzbuzz(unsigned int n) {
    return "FIZZBUZZ";
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
