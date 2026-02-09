#include <iostream>

int main(){
    const size_t numSize = 5;
    int numbers[numSize];
    int max = 0;

   for(int i = 0; i < numSize; i++){
        std::cout << "Enter a number: ";
        std::cin >> numbers[i];
   }

   for(int i = 0; i < numSize; i++){
        int current = numbers[i];
        if(current > max){
            max = current;
        }
   }
   std::cout << "The biggest number is: " << max << '\n';
    return 0;
}
