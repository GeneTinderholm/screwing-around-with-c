#include <stdio.h>

int add(int x, int y);
int sub(int x, int y);
int mul(int x, int y);
int div(int x, int y);
int (*get_op(int op))(int, int);

int main (void) {
    int x, y, op;
    printf("Enter an integer: ");
    scanf("%d", &x);
    printf("Enter another integer: ");
    scanf("%d", &y);
    puts("Which operation do you want to perform?");
    puts("1. Add");
    puts("2. Subtract");
    puts("3. Multiply");
    puts("4. Divide");
    puts("5. None");
    scanf("%d", &op);

    if (op == 5) {
        return 0;
    }

    int (*op_fun)(int, int) = get_op(op);

    int result = op_fun(x, y);

    printf("Result is: %d\n", result);
}

int add(int x, int y) {
    return x + y;
}
int sub(int x, int y) {
    return x - y;
}
int mul(int x, int y) {
    return x * y;
}
int div(int x, int y) {
    return x / y;
}

/*
 * return type                           parameters
 * of returned    signature of          for returned
 * function         get_op               function
 *
 *    int        (*get_op(int op))     (int, int)
 */
int (*get_op(int op))(int, int) {
    int (*op_arr[])(int, int) = {add, sub, mul, div};

    return op_arr[op - 1];
}
