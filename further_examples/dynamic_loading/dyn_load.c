// don't ever do this
#include <stdio.h>
#include <dlfcn.h>
#include <stdlib.h>
#include <time.h>

int main (void) {
    time_t t;
    srand((unsigned) time(&t));
    char* lib_name;

    int lib = rand() % 2;

    if (lib == 0) {
        lib_name = "libdynlib.so";
    } else {
        lib_name = "libdynlibtwo.so";
    }

    void* handle = dlopen(lib_name, RTLD_NOW);

    if (handle == NULL) {
        printf("Could not load library.\n");
        printf("%s\n", dlerror());
        return -1;
    }

    dlerror(); // clear error

    int (*fun)(void) = dlsym(handle, "fun");

    char* err;
    if ((err = dlerror()) != NULL) {
        printf("Could not load fun\n");
        printf("%s\n", err);
        dlclose(handle);
        return -1;
    }

    int result = fun();
    printf("Result was: %d\n", result);

    dlclose(handle);
}
