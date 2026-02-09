#include <iostream>
#include <ctime>

void makeCombo(int numbers[], int size);
void startGame();
void userGuess(int guesses[], int size);
void checkIncludes(int guesses[], int numbers[], int size);
void checkSpots(int guesses[], int numbers[], int size, bool & win);

int main(){
    srand(time(NULL));
    const size_t SIZE = 4;
    bool win = false;
    bool playing = true;

    int numbers[SIZE];
    makeCombo(numbers, SIZE);

    // for(int num : numbers){
    //     std::cout << " " << num << " ";
    // }

    startGame();

    int guesses[SIZE];
    
    while(playing){
        std::string answer;
        userGuess(guesses, SIZE);
        checkIncludes(guesses, numbers, SIZE);
        checkSpots(guesses, numbers, SIZE, win);
        
        if(win){
            std::cout << "\n############################################################################";
            std::cout << "\n############################ CONGRATULATIONS #############################\n";
            std::cout << "################################# YOU WIN! #################################\n";
            std::cout << "############################################################################\n";
            break;
        }

        std::cout << "Try again? ";
        std::cin >> answer;
        if(answer[0] == 'n' || answer[0] == 'N'){
            playing = false;
        }
    }

    return 0;
}

void makeCombo(int numbers[], int size){
    for(int i = 0; i < size; i++){
        numbers[i] = (rand() % 9) + 1;
    }
}

void startGame(){
    std::cout << "\n############################################################################";
    std::cout << "\n########################## Comobo Guessing Game ##########################\n";
    std::cout << "######### Guess the combination (4 numbers), in the correct order. #########\n";
    std::cout << "############################################################################\n";
}

void userGuess(int guesses[], int size){
    int test;
    for(int i = 0; i < size; i++){
        while(true){
            std::cout << "Enter number #" << i+1 << ": ";
            std::cin >> test;

            if(std::cin.fail()){
                std::cin.clear();
                std::cin.ignore(1000, '\n');
                std::cout << "Invalaid input! Please enter a number 0-9 only.\n";
                continue;
            }

            if(test > 9 || test < 0){
                std::cout << "Number must be 0-9 only!\n";
                continue;
            }

            guesses[i] = test;
            break;
        }
    }
    
}

void checkIncludes(int guesses[], int numbers[], int size){
    bool counted[4] = {false};
    int includes = 0;
    for(int i = 0; i < size; i++){
        for(int j = 0; j < size; j++){
            if(!counted[j] && guesses[i] == numbers[j]){
                includes++;
                counted[j] = true;
                break;
            }
        }
    }
    std::cout << std::endl;
    switch(includes){
        case 1: std::cout << "One correct!\n";
                break;
        case 2: std::cout << "Two correct!\n";
                break;
        case 3: std::cout << "Three correct!\n";
                break;
        case 4: std::cout << "Four correct!\n";
                break;
    }
}

void checkSpots(int guesses[], int numbers[], int size, bool & win){
    int spot = 0;
    for(int i = 0; i < size; i++){
        if(guesses[i] == numbers[i]){
            spot++;
        }
    }
    std::cout << std::endl;
    switch(spot){
        case 1: std::cout << "One in the correct spot!\n";
                break;
        case 2: std::cout << "Two in the correct spot!\n";
                break;
        case 3: std::cout << "Three in the correct spot!\n";
                break;
        case 4: win = true;
                break;
    }
}