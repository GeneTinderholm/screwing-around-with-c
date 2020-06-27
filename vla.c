#include <stdio.h>

int main (void) {
    int arr_len;
    printf("How long do you want your array?\n");
    scanf("%d", &arr_len);

    int x[arr_len];

    for (int i = 0; i < arr_len; ++i) x[i] = i;
    for (int i = 0; i < arr_len; ++i) 
        printf("array element %d = %d\n", i, x[i]);

    return 0;
}
