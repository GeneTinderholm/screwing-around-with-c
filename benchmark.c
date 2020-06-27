/*
 * TODO handle flag for running multiple time and getting average
 * TODO supress output (flag for this? which should be default?)
 */

#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <string.h>

unsigned long long get_elapsed_time (struct timeval start, struct timeval end);
unsigned long get_string_length(int argc, char** argv);
char* get_command(int argc, char** argv);

int main (int argc, char** argv) {
    if (argc < 2) {
        puts("Requires something to benchmark!");
        exit(1);
    }

    char* command = get_command(argc, argv);

    printf("Benchmarking: %s\n\n", command);

    struct timeval start, end;

    gettimeofday (&start, NULL);
    system(command);
    gettimeofday (&end, NULL);

    printf("\nElapsed Time: %lld microseconds\n", get_elapsed_time(start, end));

    return 0;
}

// returns number of microseconds between times
unsigned long long get_elapsed_time (struct timeval start, struct timeval end) {
    unsigned long long elapsed_seconds_in_microseconds = (end.tv_sec - start.tv_sec) * 1000000L;

    return elapsed_seconds_in_microseconds + end.tv_usec - start.tv_usec;
}

unsigned long get_string_length(int argc, char** argv) {
    unsigned long length = 0;

    for(int i = 1; i < argc; ++i) {
        length += strlen(argv[i]) + 1; // need space for space or final '\0'
    }

    return length;
}

char* get_command(int argc, char** argv) {
    unsigned long command_length = get_string_length(argc, argv);

    char *command = malloc(sizeof(char) * command_length);
    // don't rely on it already being all nulls, however it should only have to be null terminated
    command[0] = '\0';

    for (int i = 1; i < argc; ++i) {
        strcat(command, argv[i]);
        if (i != argc - 1) {
            strcat(command, " ");
        }
    }

    return command;
}
