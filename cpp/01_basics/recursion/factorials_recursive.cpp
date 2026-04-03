// factorials_recursive.cpp
// purpose               = demonstrate simple recursion and collecting results in a vector
// factorial(n)          = classic recursive definition (n * factorial(n-1))
// Factorials()          = recursive countdown that stores each factorial in a vector
// best practice         = guard against negative input; recursion ends at base case

#include <iostream>
#include <vector>

int factorial(int n) {
    if (n <= 1) return 1;          // base case
    return n * factorial(n - 1);   // recursive step
}

void Factorials(int userInput, std::vector<int>& factorials) {
    if (userInput < 0) return;     // recursion stop condition for negative values

    factorials.push_back(factorial(userInput)); // compute and store factorial

    // recursive countdown: n, n-1, n-2, ...
    Factorials(userInput - 1, factorials);
}

int main() {
    std::vector<int> factorials;
    int num = 0;

    std::cout << "Enter a number to print all factorials: ";
    std::cin >> num;

    if (num < 0) num = 0;          // normalize negative input

    Factorials(num, factorials);

    std::cout << "The factorials are:\n";
    for (int factor : factorials) {
        std::cout << factor << "\n";
    }

    return 0;
}


// #include <iostream>

// // print_factorials()
// // Summary: This function receives a (small) positive integer n and prints out a sequence from 0! through n!.
// // Arguments:
// //           n: The last factorial to print.
// // Returns: n!, the last calculated factorial.
// int print_factorials(int n){
//     int fact;
//     fact = n == 0 ? 1 : n * print_factorials(n - 1);
//     std::cout << fact << " ";
//     return fact;
// }

// // Main function
// int main(){
//     print_factorials(10);
//     std::cout << std::endl << std::endl << std::flush;
//     return 0;
// }