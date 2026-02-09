#include <iostream>

int main(){

    // type =   converting a value of one data type to another
    //          implicit = automatic
    //          explicit = Precede value with new data type (int) x

    double x = (int) 3.14;
    std::cout << x << '\n';
    
    char c = 65; //implicit
    std::cout << c << std::endl;
    std::cout << (char) 97 << std::endl; //explicit

    int correct = 8;
    int questions = 10;
    double score = correct / (double) questions * 100;

    std::cout << score << "%" << '\n';

    return 0;
}