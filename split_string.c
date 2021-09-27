#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void split(char *delimeter, char *string); 
char *get_string(void);

int main(int argc, char **args) {
    if (argc < 2) {
        fputs("You must supply a delimeter string\n", stderr);
        exit(1);
    }

    char *delimeter = args[1];
    char *string = NULL;

    if (isatty(fileno(stdin))) {
        if (argc < 3) {
            fputs("You must supply a string to split\n", stderr);
            exit(1);
        }
        string = args[2];
    } else {
        string = get_string();
    }
    split(delimeter, string);
}

void split(char *delimeter, char *string) {
    unsigned long skip = strlen(delimeter); 

    while (*string != '\0') {
        if (strncmp(delimeter, string, skip) != 0) {
            putchar(*string);
            string++;
        } else {
            string += skip;
            if (*string != '\0') {
                putchar('\n');
            }
        }
    }
    putchar('\n'); // TODO adds an extra newline if incoming string has a terminating newline
}

char *get_string(void) {
    // gets an arbitrary string from stdin without having gets problems
    int buff_size = 100;
    int i = 0;
    char buffer[buff_size];
    char c;
    char *result = malloc(sizeof(char));
    *result = '\0';
    unsigned long cur_len = 0;

    while ((c = getchar()) != EOF) {
        if (i == buff_size) {
            result = realloc(result, cur_len + buff_size + 1);

            for (int j = 0; j < buff_size; ++j) {
                result[cur_len + j] = buffer[j];
            }

            cur_len += buff_size;
            result[cur_len] = '\0';
            i = 0;
        }
        buffer[i] = c;
        i++;
    }
    unsigned long remainder = strlen(buffer);
    result = realloc(result, cur_len + remainder + 1);

    for (int j = 0; j < remainder; ++j) {
        result[cur_len + j] = buffer[j];
    }

    cur_len += remainder;
    result[cur_len] = '\0';
    
    return result;
}
