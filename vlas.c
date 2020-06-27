#include <stdio.h>

int sum (int len, int* arr);
int main (void) {
    printf("Please enter length of int array: ");
    int len;
    scanf("%d", &len);

    printf("Please enter int array separated by new lines: \n");
    int int_arr[len];
    for (int i = 0; i < len; ++i) {
        int el;
        scanf("%d", &el);
        int_arr[i] = el;
    }
    printf("Sum of all elements = %d\n", sum(len, int_arr));
}

int sum (int len, int* arr) {
    int count = 0;
    for (int i = 0; i < len; ++i) {
        count += arr[i];
    }

    return count;
}

