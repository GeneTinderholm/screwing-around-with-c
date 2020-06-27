#include <stdio.h>
#include <ctype.h>

int main (void) {
    char* filename = "test.txt",
        * tempfile = "temp.txt";
    FILE* fp = fopen(filename, "r");

    if (!fp) {
        printf("Unable to open %s\n", filename);
        return -1;
    }

    FILE* tp = fopen(tempfile, "w+");

    if (!tp) {
        printf("Unable to open %s\n", tempfile);
        return -1;
    }

    int c;

    while ((c = fgetc(fp)) != EOF) fputc(toupper(c), tp);

    fclose(fp);
    fclose(tp);

    rename(tempfile, filename);
    remove(tempfile);

    return 0;
}
