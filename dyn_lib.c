// gcc -g -fPIC dyn_lib.c -shared -o libdynlib.so
#include <stdio.h>
#include "dyn_lib.h"

void fun(void) {
    printf("Being called via shared library.\n");
}
