#include <iostream>
#include <cmath>

int main(){

    // foreach loop =   loop that eases the traversal over an iterable data set  
    //                  
    // std::string students[] = {"Spongebob", "Patrick", "Squidward"};
    // for(std::string student : students){
    //     std::cout << student << '\n';
    // }

    double grades[] = {65.04, 72.5, 81.4, 93.7};
    for(double grade : grades){
        std::cout << ceil(grade) << '\n';
    }

    return 0;
}