#include <iostream>
#include <cmath> // for log2 and pow functions

int main() {
    // Initialize a number to work with
    int num = 8192;

    std::cout << "--- Dividing by 2 and using log2 ---\n";

    // Loop 13 times, dividing the number by 2 each iteration
    for(int i = 0; i < 13; i++){
        num /= 2; // Divide num by 2

        // log2(num) gives the exponent x where 2^x = num
        std::cout << "log2(" << num << ") = " << log2(num) << "\t | \t";

        // pow(2, log2(num)) should give back the original number (approximately)
        std::cout << "2 to the power of " << log2(num) << " = " << pow(2, log2(num)) << '\n';
    }

    std::cout << "\n--- Checking if numbers are powers of 2 ---\n";
    int numbers[] = {3, 4, 6, 8, 10, 16, 20};
    int size = sizeof(numbers) / sizeof(numbers[0]);

    for(int i = 0; i < size; i++) {
        int n = numbers[i];

        // A number is a power of 2 if log2(n) is an integer
        double log_result = log2(n);
        bool isPowerOf2 = (std::floor(log_result) == log_result);

        std::cout << n << " is ";
        if(isPowerOf2)
            std::cout << "a power of 2.\n";
        else
            std::cout << "not a power of 2.\n";
    }

    std::cout << "\n--- Using pow to generate powers of 2 ---\n";

    // Print powers of 2 from 2^0 to 2^10
    for(int i = 0; i <= 10; i++){
        int power = pow(2, i); // 2^i
        std::cout << "2^" << i << " = " << power << '\n';
    }

    return 0;
}
