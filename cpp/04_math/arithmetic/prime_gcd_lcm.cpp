#include <iostream>
#include <numeric> // for std::gcd and std::lcm
#include <cmath>   // for sqrt

// --------------------------
// Self-written functions
// --------------------------

// isPrime = checks if a number is prime
//           A prime number is a number greater than 1
//           that has no divisors other than 1 and itself
bool isPrime(int n) {
    if (n <= 1) return false;       // numbers <= 1 are not prime
    if (n <= 3) return true;        // 2 and 3 are prime
    if (n % 2 == 0 || n % 3 == 0) return false; // eliminate multiples of 2 or 3

    // check remaining divisors up to sqrt(n)
    for (int i = 5; i * i <= n; i += 6) {
        if (n % i == 0 || n % (i + 2) == 0)
            return false;
    }
    return true;
}

// gcd = greatest common divisor of two numbers
//       The largest number that divides both numbers evenly
int myGCD(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;  // remainder
        a = temp;
    }
    return a;
}

// lcm = least common multiple of two numbers
//       The smallest positive number divisible by both numbers
int myLCM(int a, int b) {
    return (a / myGCD(a, b)) * b;
}

// --------------------------
// Main program
// --------------------------
int main() {
    int num1, num2;

    std::cout << "Enter first number: ";
    std::cin >> num1;

    std::cout << "Enter second number: ";
    std::cin >> num2;

    std::cout << "\n--- Prime Check ---\n";
    std::cout << num1 << (isPrime(num1) ? " is prime.\n" : " is not prime.\n");
    std::cout << num2 << (isPrime(num2) ? " is prime.\n" : " is not prime.\n");

    std::cout << "\n--- GCD ---\n";
    std::cout << "Self-written gcd: " << myGCD(num1, num2) << '\n';
    std::cout << "std::gcd: " << std::gcd(num1, num2) << '\n';

    std::cout << "\n--- LCM ---\n";
    std::cout << "Self-written lcm: " << myLCM(num1, num2) << '\n';
    std::cout << "std::lcm: " << std::lcm(num1, num2) << '\n';

    return 0;
}
