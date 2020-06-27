// challeng simulating loops with goto
// it's supposed to look like garbage
#include <stdio.h>

void print_first_row (int rows);
void print_middle_rows (int num_rows);
void print_middle_row (int row_num, int num_rows);
void print_last_row (int num_rows);
void print_char_n_times (char c, int n);

int main (void) {
    printf("How many rows would you like? ");
    int rows;
    scanf("%d", &rows);
    print_first_row(rows);
    print_middle_rows(rows);
    print_last_row(rows);
}

void print_first_row (int rows) {
    print_char_n_times(' ', rows - 1);
    putchar('*');
    putchar('\n');
}

void print_middle_rows (int num_rows) {
    int count = 0;

    if (num_rows <= 2)
        goto end_loop;

begin_loop:
    print_middle_row(count + 2, num_rows);
    ++count;
    if (count != (num_rows - 2))
        goto begin_loop;

end_loop:;
}

void print_middle_row (int row_num, int num_rows) {
    int first_spaces = num_rows - row_num,
        middle_spaces = 1 + 2 * (row_num - 2);

    print_char_n_times(' ', first_spaces);
    putchar('*');
    print_char_n_times(' ', middle_spaces);
    putchar('*');
    putchar('\n');
}

void print_last_row (int rows) {
    if (rows > 1) {
        print_char_n_times('*', 2 * rows - 1);
        putchar('\n');
    }
}

void print_char_n_times (char c, int n) {
    int count = 0;

    if (n <= 0)
        goto end_loop;

begin_loop:
    putchar(c);
    ++count;
    if (count < n)
        goto begin_loop;

end_loop:; // null statement with a label 
// above comment exists because I misread my own code several times
}
