#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void print_file_lines(FILE *fp, char c);
bool check_line_for_character(char *line, char c);
void strip_newline(char *line);

int main (int argc, char **args) {
    if (argc < 3) {
        puts("This program requires 2 command line arguments, a character and a filename");
    }

    char character = args[1][0];
    char *filename = args[2];

    FILE *fp = fopen(filename, "r");

    if (!fp) {
        printf("Could not open file \"%s\" for reading\n", filename);
        return 1;
    }

    print_file_lines(fp, character);

    return 0;
}

void print_file_lines(FILE *fp, char c) {
    size_t size = 255;
    char *curr_line = malloc(sizeof(char) * size);
    while (getline(&curr_line, &size, fp) != EOF) {
        if (check_line_for_character(curr_line, c)) {
            strip_newline(curr_line);
            puts(curr_line);
        }
    }
}

bool check_line_for_character (char *line, char c) {
    int index = -1;
    while (line[++index] != '\0')
        if (line[index] == c)
            return true;
    return false;
}

void strip_newline (char *line) {
    int index = -1;
    while (line[++index] != '\n');
    line[index] = '\0';
}
