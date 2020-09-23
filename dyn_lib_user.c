// gcc -I . -c dyn_lib_user.c -o main.o (compile)
// gcc -o a.out main.o -L. -ldynlib (link)
// export LD_LIBRARY_PATH="$LD_LIBRARY_PATH:/path/to/so/file" (shared object must be in path
// replace "." with directory containing shared object (this one is in this directory)

#include "dyn_lib.h"

int main (void) {
    fun();
    return 0;
}
