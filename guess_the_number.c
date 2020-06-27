#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main (void) {
    printf("This is a guessing game.\n");
    printf("Try to guess the number from 0-20\n");
    time_t t;
    srand((unsigned) time(&t));
    int random_number = rand() % 21;

    for (int number_of_guesses = 5; number_of_guesses > 0; --number_of_guesses) {
        int guess;
        printf("You have %d guesses\n", number_of_guesses);
        printf("Guess: ");
        scanf("%d", &guess);

        if (guess > 20 || guess < 0) {
            printf("Invalid Guess!\n");
            continue;
        }
        if (guess < random_number) {
            printf("Nope. Number is higher than that.\n");
        }
        if (guess > random_number) {
            printf("Nope. Number is lower than that.\n");
        }
        if (guess == random_number) {
            printf("You got it!. The number was %d.\n", random_number);
            return 0;
        }
    }
    printf("You lost. LOSER!\n");
}
