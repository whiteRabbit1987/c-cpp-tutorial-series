#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){

    // NUMBER GUESSING GAME
    // srand(time(NULL));
    // int min = 0;
    // int max = 10;
    // int randomNumber = (rand() % (max - min + 1)) + min;
    // printf("%i", randomNumber);

    srand(time(NULL));

    int guess = 0;
    int tries = 0;
    int min = 10;
    int max = 100;
    int answer = (rand() % (max - min + 1)) + min;

    printf("############################\n");
    printf("### NUMBER GUESSING GAME ###\n");
    printf("############################\n\n");

    do{
        printf("Guess a number between %i - %i: ", min, max);
        scanf("%i", &guess);
        tries++;

        if(guess > answer){
            printf("TOO HIGH!\n");
        } else if (guess < answer) {
            printf("TOO LOW!\n");
        } else {
            printf("CORRECT!\n");
        }

    } while (guess != answer);
    
    printf("The answer is %i.\n", answer);
    printf("It took you %i tries.", tries);

    return 0;
}