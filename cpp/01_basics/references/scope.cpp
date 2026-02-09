#include <iostream>
#include <string>

// Global variable: declared outside all functions
std::string scopeVar = "Global variable value: ";

void printNum();       // function that uses global variable
void assignLocal();    // function demonstrating local variable shadowing
void assignGlobal();   // function modifying the global variable

int main() {

    // Local variable: declared inside main
    std::string scopeVar = "Local variable value: ";

    // Function uses the global variable
    printNum(); 

    // Function assigns to global variable
    assignGlobal(); 
    std::cout << "After assignGlobal(), global variable: " << ::scopeVar << '\n';

    // Function declares a local variable with the same name (shadows global)
    assignLocal(); 

    // Accessing variables in main
    std::cout << "Inside main, local variable: " << scopeVar << '\n';
    std::cout << "Inside main, global variable: " << ::scopeVar << '\n';

    return 0;
}

void printNum() {
    // Uses the global variable because there is no local one here
    std::cout << "printNum() sees: " << scopeVar << " (global variable)" << '\n';
}

void assignLocal() {
    // Local variable shadows the global variable
    std::string scopeVar = "Local in assignLocal()";
    std::cout << "assignLocal() sees: " << scopeVar << " (local variable)" << '\n';
}

void assignGlobal() {
    // Modifies the global variable directly
    ::scopeVar = "Modified by assignGlobal()";
    std::cout << "assignGlobal() modified global variable" << '\n';
}
