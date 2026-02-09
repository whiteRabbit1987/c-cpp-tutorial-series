#include <iostream>

int main(){

    // array    =   a data structure that can hold multiple values
    //              values are accessed by an index number
    //              "kind of like a variable that holds multiple values"
    
    std::string fruits[] = {"apple", "banana", "orange"};
    std::string vegetables[] = {"tomato", "zucchini", "carrot"};
    std::string meats[] = {"beef", "bacon", "turkey"};
    std::string* foods[] = {fruits, vegetables, meats};

    for(int i = 0; i < sizeof(fruits)/sizeof(std::string); i++){
        std::cout << fruits[i] << '\n';
    }

    // for(int i = 0; i < 3; i++){
    //     for(int j = 0; j < 3; j++){
    //         std::cout << foods[i][j] << " ";
    //     }
    //     std::cout << '\n';
    // }

    // std::cout << "\n\n\n";

    // std::string names[3][3] = {
    //     {"Dennis", "Mama", "Phillip"},
    //     {"Simba", "D'Mama", "Hicks"},
    //     {"Darf", "uns", "nichtfragen"}
    // };

    // for(int i = 0; i < 3; i++){
    //     for(int j = 0; j < 3; j++){
    //         std::cout << names[i][j] << " ";
    //     }
    //     std::cout << '\n';
    // }
    return 0;
}