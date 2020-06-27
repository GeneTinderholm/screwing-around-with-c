#include <stdio.h>
#include "test2.h"

int func_two (void) {
    int i = 0;

    for (; i < 0xEFA19F; ++i);

    return i;
}
