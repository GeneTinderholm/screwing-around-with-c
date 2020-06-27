#include <stdio.h>

int internal[1000];

// returns length of array
int load_line() {
    int c;
    int i = 0;
    
    while ((c = getchar()) != '\n')
        internal[i++] = c;

    return i;
}
void print_reverse(int arr_length) {
    while (arr_length > 0) 
        putchar(internal[--arr_length]);
    putchar('\n');
}

int main(void) {
    while(1) {
        int i = load_line();
        print_reverse(i);
    }
}
