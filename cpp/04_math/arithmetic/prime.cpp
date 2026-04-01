// find_primes.cpp
// purpose               = scan an array and collect prime numbers into a vector
// input                 = raw array + size + output vector reference
// prime test            = simple trial division from 2 to n-1
// best practice         = avoid eof-style loops; use size_t for array sizes

#include <iostream>
#include <vector>

void findPrimes(const int arr[], size_t size, std::vector<int>& primes) {

    for (size_t i = 0; i < size; i++) {
        int n = arr[i];
        if (n < 2) continue;          // 0 and 1 are not prime

        bool isPrime = true;

        // trial division: check divisors from 2 to n-1
        for (int j = 2; j < n; j++) {
            if (n % j == 0) {         // divisible → not prime
                isPrime = false;
                break;
            }
        }

        if (isPrime)
            primes.push_back(n);
    }

    // output results
    if (!primes.empty()) {
        std::cout << "The prime numbers in the array are: ";
        for (int prime : primes)
            std::cout << prime << " ";
        std::cout << "\n";
    }
    else {
        std::cout << "No prime numbers found in the array.\n";
    }
}

int main() {

    int numbers[]{1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11};
    size_t numSize = sizeof(numbers) / sizeof(int);
    std::vector<int> numVec;

    int evens[]{4, 6, 8, 10};
    size_t evenSize = sizeof(evens) / sizeof(int);
    std::vector<int> evenVec;

    findPrimes(numbers, numSize, numVec);
    findPrimes(evens, evenSize, evenVec);

    return 0;
}
