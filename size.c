#include <stdio.h>
#include <stdbool.h>

int main (void) {
    int _b = sizeof(_Bool);
    int b = sizeof(bool);
    int c = sizeof(char);
    int s = sizeof(short);
    int i = sizeof(int);
    int f = sizeof(float);
    int l = sizeof(long);
    int ll = sizeof(long long);
    int d = sizeof(double);
    int st = sizeof(size_t);
    int ld = sizeof(long double);

    printf("_Bool:       %d\n", _b);
    printf("bool:        %d\n", b);
    printf("char:        %d\n", c);
    printf("short:       %d\n", s);
    printf("int:         %d\n", i);
    printf("float:       %d\n", f);
    printf("long:        %d\n", l);
    printf("long long:   %d\n", ll);
    printf("double:      %d\n", d);
    printf("size_t:      %d\n", st);
    printf("long double: %d\n", ld);
}
