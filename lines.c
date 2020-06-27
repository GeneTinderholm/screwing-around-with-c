#include <stdio.h>
#include <stdlib.h>

int main (void) {
    char* filename = "test.txt";
    FILE* fp = fopen(filename, "r");

    if (!fp) {
        printf("Unable to open file.");
        return -1;
    }
    int count = 0;
    int c;
    while ((c = fgetc(fp)) != EOF) {
        if (c == '\n') ++count;
    }

    fclose(fp);
    printf("Lines: %d\n", count);
}
