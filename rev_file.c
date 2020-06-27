#include <stdio.h>

int main (void) {
    char* filename = "test.txt";
    FILE* fp = fopen(filename, "r");

    if (!fp) {
        printf("Unable to open file %s\n", filename);
        return -1;
    }

    fseek(fp, 0, SEEK_END);
    long len = ftell(fp);

    for (int i = 1; i <= len; ++i) {
        // -2 because fgetc advances by 1
        fseek(fp, -i , SEEK_END);
        putchar(fgetc(fp));
    }
    putchar('\n');

    fclose(fp);

    return 0;
}
