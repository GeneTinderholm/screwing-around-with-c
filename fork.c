#include <stdio.h>
#include <unistd.h>
int main (void) {
    int pid = fork();

    // pid will be the process id of the child process if you're in the parent process.
    // in the child process the value will be 0
    if (pid > 0) {
        printf("in parent process\n");
    } else {
        printf("in child process\n");
    }
}
