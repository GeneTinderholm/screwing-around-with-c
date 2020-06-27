#include <stdio.h>
#include <malloc.h>

struct myArray {
    int length;
    int array[];
};

void init_my_array(int len, struct myArray* ma);
void print_my_array(struct myArray* ma);
int main (void) {
    int len;
    printf("How long would you like your array? ");
    scanf("%d", &len);

    struct myArray* ma = malloc(sizeof(struct myArray) + sizeof(int) * len);
    init_my_array(len, ma);
    print_my_array(ma);
}

void init_my_array(int len, struct myArray* ma) {
    ma->length = len;
    for (int i = 0; i < len; ++i) {
        ma->array[i] = len - i;
    }
}

void print_my_array(struct myArray* ma) {
    printf("Length of myArray: %d\n", ma->length);
    for (int i = 0; i < ma->length; ++i) {
        printf("Element %2d = %d\n", i, ma->array[i]);
    }
}
