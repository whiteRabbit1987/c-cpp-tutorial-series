#include <iostream>
#include <string>
#include <typeinfo> // Required for the print_values method
#include "class_template.h"

// Class Template Instantiation =  The process of creating a concrete class type from the template blueprint.
//                                  This must be done explicitly by specifying the types in angle brackets (<...>)
//                                  (e.g., Pair<int, float>).

// Type Safety                  =   The compiler ensures that once a template is instantiated (e.g., as Pair<int, float>),
//                                  the object only holds the declared types (int and float).

int main() {
    
    // --- 1. Instantiation with Basic Types ---
    // Creates a Pair object that holds an integer and a floating-point number.
    Pair<int, float> item_price(5, 12.99f); 

    std::cout << "--- 1. Basic Type Pair (int, float) ---" << '\n';
    item_price.print_values();
    std::cout << "Quantity: " << item_price.first << ", Total Price: $" << item_price.second * item_price.first << "\n\n";

    // --- 2. Instantiation with Custom Types ---
    // Creates a Pair object that holds a standard string and a boolean.
    Pair<std::string, bool> user_status("Admin", true);

    std::cout << "--- 2. Custom Type Pair (string, bool) ---" << '\n';
    user_status.print_values();
    if (user_status.second) {
        std::cout << user_status.first << " is currently active.\n";
    } else {
        std::cout << user_status.first << " is inactive.\n";
    }
    std::cout << '\n';

    // --- 3. Instantiation with Same Types ---
    // Creates a Pair object that holds two integers (useful for 2D coordinates).
    Pair<int, int> coordinates(100, 200);

    std::cout << "--- 3. Same Type Pair (int, int) ---" << '\n';
    coordinates.print_values();
    
    return 0;
}