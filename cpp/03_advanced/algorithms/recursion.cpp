// recusion =   a programming technique where a function invokes itself from within
//              break a complex concept into a repeatable single step

// (iterative vs recursive)

// advantages   =   less code and is cleaner
//                  usefull for sorting and searching algorithms

// disadvantages    =   uses more memory
//                      slower


// iterative below
// #include <iostream>
// void walk(int steps);
// int main(){
    
//     walk(5);

//     return 0;
// }
// void walk(int steps){
//     for(int i = 0; i < steps; i++){
//         std::cout << "You take a step!\n";
//     }
// }

// recusive below
// #include <iostream>
// void walk(int steps);
// int main(){
    
//     walk(5);

//     return 0;
// }
// void walk(int steps){
//     if(steps > 0){
//         std::cout << "You take a step!\n";
//         walk(steps - 1);
//     }
// }


#include <iostream>
int factorial(int num);
int main(){
    int number;
    std::cout << "Enter a number: ";
    std::cin >> number;
    int result = factorial(number);
    std::cout << result;
    return 0;
}
int factorial(int num){
    // for(int i = num -1; i > 0; i--){
    //     num *= i;
    // }
    //return num;
    if(num > 1){
        return num * factorial(num -1);
    } else {
        return 1;
    }
    
}