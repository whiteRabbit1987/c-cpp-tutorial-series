#include <iostream>

int main(){

    const int ROWS = 3;
    const int COLS = 3;
    std::string cars[ROWS][COLS] = {
                {"Mustang", "Escape", "F-150"},
                {"Corvette", "Equinox", "Silverado"},
                {"Challenger", "Durango", "Ram 1500"}
    };

    for(int r = 0; r < ROWS; r++){
        for(int c = 0; c < COLS; c++){
            std::cout << cars[r][c] << " - ";
        }
        std::cout << "\n";
    }
    return 0;
}