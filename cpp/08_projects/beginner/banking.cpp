#include <iostream>
#include <iomanip>

void showBalance(double balance);
double deposit();
double withdraw(double balance);

int main(){

    double balance = 0.0;
    int choice = 0;
    bool isRunning = true;

    std::cout << "#####################################\n";
    std::cout << "#### ATM Banking programm online ####\n";
    std::cout << "#####################################\n";

    while (isRunning){
        std::cout << "\nEnter your choice:\n";
        std::cout << "1. Show Balance\n";
        std::cout << "2. Deposit Money\n";
        std::cout << "3. Withdraw Money\n";
        std::cout << "4. Exit\n";
        std::cout << "Enter: ";
        std::cin >> choice;

        std::cin.clear();
        fflush(stdin);

        switch (choice){
        case 1:
            showBalance(balance);
            break;
        case 2:
            balance += deposit();
            showBalance(balance);
            break;
        case 3:
            balance -= withdraw(balance);
            showBalance(balance);
            break;
        case 4:
            isRunning = false;
            std::cout << "\n*******************";
            std::cout << "\nGodbye!\n";
            break;
        default:
            std::cout << "\n*******************";
            std::cout << "\nInvalid input, try again!\n";
            break;
        }
    }

    return 0;
}

void showBalance(double balance){
    std::cout << "\n*******************";
    std::cout << "\nCurrent balance: $" << std::setprecision(2) << std::fixed << balance << '\n';
}
double deposit(){
    double amount = 0.0;
    std::cout << "\n*******************";
    std::cout << "\nEnter deposit amount: \n";
    std::cin >> amount;

    if(amount > 0){
        return amount;
    } else {
        std::cout << "That's not a valid amount\n";
        return 0;
    }
    
}
double withdraw(double balance){
    double amount = 0.0;
    std::cout << "\n*******************";
    std::cout << "\nHow much would you like to withdraw: \n";
    std::cin >> amount;

    if(balance >= amount){
        return amount;
    } else {
        std::cout << "Insufficient funds!\n";
        return 0;
    }
}