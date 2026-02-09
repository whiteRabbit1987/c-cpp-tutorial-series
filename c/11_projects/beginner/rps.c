#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

int getComputerChoice();
int getUserChoice();
char checkWinner(int userChoice, int computerChoice);

int main(){

    const char *words[3] = {"Rock", "Paper", "Scissors"};
    char playGame = '\0';
    int computerScore = 0;
    int userScore = 0;
    char outcome = '\0';

    printf("*** ROCK PAPER SCISSORS ***\n");
    
    do{
        printf("Choose an option\n");
        printf("1. ROCK\n");
        printf("2. PAPER\n");
        printf("3. SCISSORS\n");

        int computerChoice = getComputerChoice();
        int userChoice = getUserChoice();
        printf("You choose %s. Computer choose %s.\n", words[userChoice - 1], words[computerChoice - 1]);
        outcome = checkWinner(userChoice, computerChoice);
        if(outcome == 'u'){
            userScore++;
        } else if (outcome == 'c'){
            computerScore++;
        }
        printf("You: %i Computer: %i\n", userScore, computerScore);

        printf("Would you like to play again (Y/N): ");
        scanf(" %c", &playGame);
    } while(playGame == 'Y' || playGame == 'y');

    return 0;
}

int getComputerChoice(){
    srand(time(0));

    int min = 1;
    int max = 3;
    int computerChoice = (rand() % (max - min + 1)) + min;

    return computerChoice;
}

int getUserChoice(){
    int userChoice = 0;

    printf("Enter your choice: ");
    scanf("%i", &userChoice);
}

char checkWinner(int userChoice, int computerChoice){
    if(userChoice == computerChoice){
        printf("It's a draw!\n");
        return 'd';
    } else if((userChoice == 1 && computerChoice == 2) || (userChoice == 2 && computerChoice == 3) || (userChoice == 3 && computerChoice == 1)){
        printf("Computer wins this round!\n");
        return 'c';
    } else {
        printf("You win this round!\n");
        return 'u';
    }
}