#include <iostream>
#include <ctime>

int main(){

    srand(time(0));
    int min = 1;
    int max = 100;
    int randNum = (rand() % (max - min + 1)) + min;
    int guess = 0;
    int tries = 0;

    std::cout << "#####################################\n";
    std::cout << "#### Random number Guessing GAME ####\n";
    std::cout << "#####################################\n";

    while(guess != randNum){
        std::cout << "\nGuess a number between " << min << " and " << max << ": ";
        std::cin >> guess;
        tries++;

        if(guess > randNum){
            std::cout << "TOO HIGH! Guess again!";
        } else if (guess < randNum) {
             std::cout << "TOO LOW! Guess again!";
        } else {
              std::cout << "Correct! It took you " << tries << " tries!\n";
        }
    }
    std::cout << "#####################################\n";

    return 0;
}