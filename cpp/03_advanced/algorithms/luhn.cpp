// Luhn Algorithm 
// Used to validate/test credit card numbers

#include <iostream>

// Preprocessed functions

int getDigit(const int number);
int sumOddDigits(const std::string cardNumber);
int sumEvenDigits(const std::string cardNumber);

// Start of MAIN

int main(){
    std::string cardNumber;
    int result = 0;

    std::cout << "Enter a credit card #: ";
    std::cin >> cardNumber;

    result = sumEvenDigits(cardNumber) + sumOddDigits(cardNumber);

    if(result % 10 == 0){
        std::cout << cardNumber << " is valid";
    } else {
        std::cout << cardNumber << " is not valid";
    }

    return 0;
}

// User Defined functions

int getDigit(const int number){
    // if input is 18
    // 18 % 10 = 8         18 / 10 = 1 % 10 = 1
    // returns 9
    return number % 10 + (number / 10 % 10);
}

int sumOddDigits(const std::string cardNumber){
    int sum = 0;

    for(int i = cardNumber.size() -1; i >= 0; i-=2){
        sum += cardNumber[i] - '0';
    }

    return sum;
}

int sumEvenDigits(const std::string cardNumber){
    int sum = 0;

    for(int i = cardNumber.size() -2; i >= 0; i-=2){
        sum += getDigit((cardNumber[i] - '0') * 2);
    }

    return sum;
}