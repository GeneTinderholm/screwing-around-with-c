#include <stdio.h>

int main (void) {
    int number = 10;
    int* pnumber = NULL;

    printf("number's address:  %p\n", &number);
    printf("number's value:    %d\n", number);

    pnumber = &number;

    printf("pnumber's address: %p\n", &pnumber);
    printf("pnumber's size:    %d\n", (int) sizeof(pnumber));
    printf("pnumber's value:   %p\n", pnumber);
    printf("value pointed to:  %d\n", *pnumber);
}
