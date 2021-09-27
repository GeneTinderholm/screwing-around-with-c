#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

const int INT_BITS = sizeof(int) * CHAR_BIT;

void get_binary_string(int x, char** buff) {
    int offset = INT_BITS - 1;
    int flag = 1 << offset;
    char* string = *buff;

    for (int i = 0; i < INT_BITS; ++i, x <<= 1, ++string) {
        *string = x & flag ? '1' : '0';
    }
    *string = 0;

    while(**buff == '0') {
        ++(*buff);
    }
}

int main(int argc, char** argv) {
    int res = atoi(argv[1]);
    char buff[INT_BITS + 1];
    char *ptr = buff;
    get_binary_string(res, &ptr);
    printf("%s\n", ptr);
}
