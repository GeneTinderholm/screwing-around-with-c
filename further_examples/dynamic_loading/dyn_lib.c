// gcc -g -fPIC dyn_lib.c -shared -o libdynlib.so
#include <stdio.h>

int fun(void) {
    printf("In lib one\n");
    return 5;
}
