#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

void handle_file (char *filename);
void handle_stdin (void);
int* get_words_and_characters (FILE *stream);
void print_words_and_characters (int *vals);

int main (int argc, char **args) {
    if (argc <= 1)
        handle_stdin();
    else
        handle_file(args[1]);

    return 0;
}

void handle_file (char *filename) {
    FILE *fp = fopen(filename, "r");

    if (fp) {
        int *res = get_words_and_characters(fp);
        print_words_and_characters(res);
        fclose(fp);
    }
}

void handle_stdin (void) {
    int *res = get_words_and_characters(stdin);
    print_words_and_characters(res);
}

int* get_words_and_characters (FILE *stream) {
    int *ret = malloc(sizeof(int) * 2),
        c = '\0';

    ret[0] = 0;
    ret[1] = 0;

    while ((c = getc(stream)) != EOF) {
        ++ret[1];
        if (isspace(c))
            ++ret[0];
    }

    return ret;
}

void print_words_and_characters (int *vals) {
    printf("The number of words in the file are:      %d\n", *vals);
    printf("The number of characters in the file are: %d\n", *(vals + 1));
}
