#include <stdio.h>
#include <signal.h>

// ps to get process id
// restart with kill -s SIGCONT {PID}
int main (void) {
    printf("Rasing SIGSTOP\n");
    raise(SIGSTOP);
    printf("continuing...\n");
    return 0;
}
