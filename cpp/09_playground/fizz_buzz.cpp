#include <iostream>


int main(){
    int n;
    std::cout << "Enter a positive integer: " << std::flush;
    std::cin >> n;

    // FizzBuzz
    for(int i = 1; i <= n; i++){
        
        if(i % 3 == 0 && i % 5 == 0){
            std::cout << "Number: " << i << " = FizzBuzz" << std::endl;
            continue;
        } else if(i % 3 == 0){
            std::cout << "Number: " << i << " = Fizz" << std::endl;
            continue;
        } else if(i % 5 == 0){
            std::cout << "Number: " << i << " = Buzz" << std::endl;
            continue;
        } else {
            continue;
        }
    }
    
    std::cout << std::endl << std::flush;
    return 0;
}