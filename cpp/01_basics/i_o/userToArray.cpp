#include <iostream>
#include <string>

int main(){

    std::string foods[5];
    int size = sizeof(foods)/sizeof(foods[0]);

    for(int i = 0; i < size; i++){
        std::cout << "Enter a food you like or 'q' to quit #" << i+1 << " : ";
        std::getline(std::cin, foods[i]);
        if(foods[i] == "q"){
            foods[i].clear();
            break;
        }
    }

    std::cout << "You like: " << "\n";
    for(int i = 0; !foods[i].empty(); i++){
        std::cout << foods[i] << "\n";
    }

    return 0;
}