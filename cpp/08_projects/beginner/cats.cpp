#include <iostream>

int main(){
    const size_t SIZE = 4;
    std::string questions[SIZE] = {"1. How many lifes does a cat have?", "2. How do you train a cat?", "3. How to punish a cat?", "4. How to make your cat loose weight?"};
    std::string options[][4] = {    {"A. 7", "B. 8", "C. 9", "D. 1"}, 
                                    {"A. Treats", "B. 2xTreats", "C. 3xTreats", "D. All of the above"}, 
                                    {"A. More Treats", "B. Play time", "C. no vaccum", "D. balkony time"}, 
                                    {"A. Better food", "B. Even More treats", "C. Salmon", "D. All of the above"}
                                };
    char answerKey[] = {'C', 'D', 'B', 'D'};
    char guess;
    int points;
    
    for(int i = 0; i < sizeof(questions)/sizeof(questions[0]); i++){
        std::cout << "*******************\n";
        std::cout << questions[i] << "\n";
        std::cout << "*******************\n";
         for(int k = 0; k < sizeof(options[i])/sizeof(options[i][0]); k++){
            std::cout << options[i][k] << "\n";
        }
        std::cin >> guess;
        guess = toupper(guess);
        if(answerKey[i] == guess){
            points++;
            std::cout << "Correct!\n";
        } else {
            std::cout << "Wrong\n";
            std::cout << "Correct answer: " << answerKey[i] << '\n';
        }
    }
    std::cout << "#############################\n";
    std::cout << "#            REULTS         #\n";
    std::cout << "#############################\n";
    std::cout << "You scored: " << (points/(double)SIZE) * 100 << " %\n";
    std::cout << "*******************\n";
    std::cout << "*******************\n";
    return 0;
}