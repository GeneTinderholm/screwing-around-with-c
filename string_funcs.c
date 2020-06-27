#include <stdio.h>
#include <string.h>
#include <stdbool.h>

int string_length (char* str) {
    int count;
    for (count = 0; str[count] != '\0'; ++count);
    return count;
}

void string_copy (char* result, char* str1, char* str2) {
    int count;
    for (count = 0; str1[count] != '\0'; ++count) {
        result[count] = str1[count];
    }

    int second_count;
    for (second_count = 0; str2[second_count] != '\0'; ++second_count) {
        result[count + second_count] = str2[second_count];
    }

    result[count + second_count] = '\0';
}

bool string_compare(char* a, char* b) {
    int i;
    for (i = 0; a[i] != '\0' && b[i] != '\0'; ++i) {
        if (a[i] == b[i]) continue;
        return false;
    }
    return a[i] == b[i];
}

int main (void) {
    char test_string[] = "This is a test string. I will be doing tests with it";

    /* printf("The length of test_string is: %d\n", string_length(test_string)); */
    /* printf("official length: %d\n", (int) strlen(test_string)); */

    char result[100];
    char test1[] = "This is a test string. ";
    char test2[] = "I will do tests with it.";
    /* string_copy(result, test1, test2); */
    /* printf("%s\n", result); */
    char testa[] = "test string please ignore";
    char testb[] = "test string please ignore";
    printf("%d\n", string_compare(testa, testb));
    printf("%d\n", string_compare("things", "stuff"));
    printf("%d\n", string_compare("things", "thingsssss"));
}
