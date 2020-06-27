//This ended up grosser than I would like, but the general case is kind of annoying
//TODO come back with a more elegant solution
//have to link math library -lm
//"numbers.txt"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool is_prime(int x);
bool is_even(int x);
int parse_numbers(char *str, int **out);
void reset_string(char *str, int len);

int main (void) {
    FILE *fp = fopen("numbers.txt", "r");

    if (!fp) {
        puts("Cannot open file!");
        exit(1);
    }

    char buff[255];

    while (fgets(buff, 255, fp)) {
        int *int_buff = malloc(sizeof(int)),
            len = parse_numbers(buff, &int_buff);

        for (int i = 0; i < len; ++i) {
            if (is_prime(int_buff[i])) {
                printf("Found prime: %d\n", int_buff[i]);
            }
            else if (is_even(int_buff[i])) {
                printf("Found even: %d\n", int_buff[i]);
            }
            else {
                printf("Found odd: %d\n", int_buff[i]);
            }
        }
    }
}

bool is_prime (int x) {
    if (x <= 0)
        return false;

    for (int i = 2; i <= (int) sqrt((double) x); ++i) {
        if (x % i == 0)
            return false;
    }

    return true;
}

bool is_even (int x) {
    return x % 2 == 0;
}

int parse_numbers (char *str, int **out) {
    int index = 0,
        temp = 0,
        count = 0;
    char buff[255],
         c;

    reset_string(buff, 255);

    while ((c = *(str++)) != '\0') {
        if (c >= '0' && c <= '9' || c == '-') {
            buff[index++] = c;
        } else {
            /* gets the number out of buff,
             * resizes the array that was passed in,
             * purges buff
             */
            if (index > 0) {
                sscanf(buff, "%d", &temp);
                ++count;
                if (!realloc(*out, sizeof(int) * count)) {
                    puts("Error realloc'ing memory");
                    exit(1);
                }
                (*out)[count - 1] = temp;
                reset_string(buff, 255);
                index = 0;
            }
        }
    }

    // get the last number out
    if (index > 0) {
        sscanf(buff, "%d", &temp);
        ++count;
        if (!realloc(*out, sizeof(int) * count)) {
            puts("Error realloc'ing memory");
            exit(1);
        }
        (*out)[count - 1] = temp;
        reset_string(buff, 255);
        index = 0;
    }

    return count;
}

void reset_string (char *str, int len) {
    for (int i = 0; i < len; ++i) {
        str[i] = '\0';
    }
}
