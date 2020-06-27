#include <stdio.h>

int main (void) {
    printf("FILE: %s\n", __FILE__);
    printf("LINE: %d\n", __LINE__);
    printf("func: %s\n", __func__);
    printf("DATE: %s\n", __DATE__);
    printf("TIME: %s\n", __TIME__);
    printf("STDC: %d\n", __STDC__);
}
