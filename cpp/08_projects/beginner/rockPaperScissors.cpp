#include <iostream>
#include <ctime>

int main(){
    srand(time(NULL));
    std::string computer[] = {"rock", "paper", "scissors"};
    std::string userChoice = "";
    int compScore = 0;
    int userScore = 0;
    char playAgain = 'y';
    
    std::cout << "###########################\n";
    std::cout << "# Rock | Paper | Scissors #\n";
    std::cout << "###########################\n";

    while(playAgain == 'y' || playAgain == 'Y'){
            int idx = rand() % 3;
            std::string computerChoice = computer[idx];
            std::cout << "\nEnter your choice (rock|paper|scissors): ";
            std::cin >> userChoice;
            std::cout << "\nComputer choose: " << computerChoice << '\n';
            std::cout << "You choose: " << userChoice << '\n'; 

            if(computerChoice == userChoice){
                std::cout << "\nIt's a tie!";
                compScore++;
                userScore++;
            } else if(computerChoice == "rock" && userChoice == "scissors" || computerChoice == "paper" && userChoice == "rock" || computerChoice == "scissors" && userChoice == "paper"){
                std::cout << "\nComputer wins! You LOOSE!\n";
                compScore++;
            } else {
                std::cout << "\nYou WIN!\n";
                userScore++;
            }
    
            std::cout << "\n###########################\n";
            std::cout << "Computer: " << compScore << '\t';
            std::cout << "Your score: " << userScore << '\n';
            std::cout << "###########################\n";

            std::cout << "\nPlay again (y|n): ";
            std::cin >> playAgain;
    }
    return 0;
}

