// gcc -o main dyn_load.c -ldl
// export LD_LIBRARY_PATH="$LD_LIBRARY_PATH:/path/to/libdynlib.so"
#include <stdio.h>
#include <dlfcn.h>
#include <stdlib.h>

int main (void) {
    // so is generated from dyn_lib.c
    void* handle = dlopen("libdynlib.so", RTLD_NOW);

    if (handle == NULL) {
        printf("Could not load library.\n");
        printf("%s\n", dlerror());
        return -1;
    }
    printf("Successfully loaded library.\n");

    dlerror(); // clear error

    void (*fun)(void) = dlsym(handle, "fun");

    char* err;
    if ((err = dlerror()) != NULL) {
        printf("Could not load fun\n");
        printf("%s\n", err);
        dlclose(handle);
        return -1;
    }

    printf("Successfully loaded fun\n");
    fun();

    dlclose(handle);
}
