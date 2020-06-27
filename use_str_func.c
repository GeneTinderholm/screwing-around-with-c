#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char* rev_string (char* str) {
    int len = strlen(str);
    char* new_str = malloc(len + 1);

    for(int i = 0; i < len; ++i) {
        new_str[i] = str[len - 1 - i];
    }
    new_str[len] = '\0';

    return new_str;
}

void display_rev_strig (char* str) {
    char* rev_str = rev_string(str);

    printf("%s\n", rev_str);

    free(rev_str);
}

char** get_n_strings (int n) {
    char** x = malloc(sizeof(char*) * n);
    for(int i = 0; i < n; ++i) {
        char y[100];
        scanf("%s", y);

        char* curr = malloc(strlen(y) + 1);
        strcpy(curr, y);
        x[i] = curr;
    }

    return x;
}

void sort_strings (int stringc, char** strings) {
    int run_again;
    while (run_again) {
        run_again = 0;
        for (int i = 0; i < stringc - 1; ++i) {
            if (strcmp(strings[i], strings[i + 1]) > 0) {
                // swap and set run_again
                char* tmp = strings[i];
                strings[i] = strings[i + 1];
                strings[i + 1] = tmp;
                run_again = 1;
            }
        }
    }
}

int main (void) {
    int x;
    printf("Please enter a number of strings: ");
    scanf("%d", &x);
    char** strings = get_n_strings(x);
    sort_strings(x, strings);
    printf("\nThe sorted strings are: \n");
    for (int i = 0; i < x; ++i) {
        printf("%s\n", strings[i]);
    }
}
