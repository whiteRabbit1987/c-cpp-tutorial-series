#include <iostream>


int main(){

    // char symbol = '*';

    // for(int i = 0; i < 10; i++){
    //     for(int j = 0; j < i; j++){
    //         std::cout << symbol;
    //     }
    //     std::cout << std::endl;
    // }

    for(int i = 1; i <= 10; i++){
        for(int j = 1; j <= 10; j++){
            if((j * i) % 2){
                std::cout << "#" << "\t";
                continue;
            }
            std::cout << j * i << "\t";
        }
        std::cout << std::endl;
    }

    return 0;
}