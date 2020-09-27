#include <signal.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

/*
 * Asks the user simple multiplication questions, if they take longer than 5 seconds to answer one of them, the game ends.
 */

#define STDOUT 1
void handle_sigint(int);
void handle_sigalrm(int);

// only supports a score of 9999 for now
int count_correct = 0;

int main (void) {
    signal(SIGINT, handle_sigint);
    signal(SIGALRM, handle_sigalrm);

    while (1) {
        srand(time(0));
        int a = rand() % 10;
        int b = rand() % 10;
        printf("What is %d times %d? ", a, b);
        int answer = a * b;
        int user_answer;
        alarm(5);
        scanf("%d", &user_answer);
        if (answer == user_answer) {
            ++count_correct;

            // not strictly necessary, but I like reseting the alarm explicitly.
            alarm(0);
        } else {
            printf("Wrong answer.\n");
            printf("Number correct: %d.\n", count_correct);
            return 0;
        }
    }
}

// trying to only use async safe functions here
void handle_sigint(int sig_code) {
    if (sig_code == SIGINT) {
        int count_copy = count_correct;
        char count[5];

        // convert count to null terminated string
        for (int i = 0; i < 4; ++i) {
            int remainder = count_copy % 10;
            count_copy /= 10;
            count[3 - i] = '0' + remainder;
        }
        count[4] = '\0';

        // find first non 0 character in count
        int index = 0;
        while (count[index] == '0') {
            ++index;
        }

        char message[25] = "\nNumber correct: ";
        strcat(message, &count[index]);
        strcat(message, "\n");
        write(STDOUT, message, strlen(message));
        exit(0);
    } else {
        exit(1);
    }
}

void handle_sigalrm(int sig_code) {
    if (sig_code == SIGALRM) {
        char* message = "\nTook too long. Failure.";
        write(STDOUT, message, strlen(message));
        raise(SIGINT);
    } else {
        exit(1);
    }
}
