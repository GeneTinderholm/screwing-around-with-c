#include <stdio.h>
#include <signal.h>
#include <stdlib.h>

volatile int flag = 0;
void fpe_handler(int signum);

int main (void) {
    int a = 42;
    int b = 0;
    void (*sig_handle_return)(int) = signal(SIGFPE, fpe_handler);

    if (sig_handle_return == SIG_ERR) {
        perror("Signal error: ");
        return 1;
    }
    int c = a / b;

    printf("C is %d\n", c);

    return 0;
}

void fpe_handler(int signum) {
    printf("Signal recieved: %d\n", signum);
    if (signum == SIGFPE) {
        printf("Whoops, divided by 0\n");
        fflush(stdout);
        // exit gracefully
        exit(0);
    } else {
        exit(1);
    }
}
