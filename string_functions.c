#include <stdlib.h>
// gcc -c string_functions.c
// ar rcs string_functions.a string_functions.o

// counts the frequency of c in the string
int char_freq (char* string, char c) {
    int count = 0,
        i = 0;

    while (string[i] != '\0') {
        if (string[i] == c)
            ++count;
        ++i;
    }

    return count;
}

// strips all non alphabetical characters from the string
char* strip_string (char* string) {
    int count = 0,
        i = 0;

    while (string[i] != '\0') {
        char c = string[i];
        if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'))
            ++count;
        ++i;
    }
   
    char* result = malloc(sizeof(char) * (count + 1)); // null terminator

    i = 0;
    int j = 0;

    while (j < count) {
        char c = string[i]; 
        if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z')) {
            result[j] = string[i];
            ++j;
        }
        ++i;
    }
    result[count] = '\0';

    return result;
}

// finds length of string
int str_len (char* string) {
    int i = 0;
    while (string[i] != '\0')
        ++i;
    return i;
}

// concatenates two strings returning a new one
char* str_cat (char* a, char* b) {
    int len_a = str_len(a),
        len_b = str_len(b),
        i = 0;

    char* result = malloc(sizeof(char) * (len_a + len_b + 1));

    for (; i < len_a; ++i) {
        result[i] = a[i];
    }

    // <= should copy null terminator
    for (int j = 0; j <= len_b; ++j) {
        result[i + j] = b[j];
    }

    return result;
}
