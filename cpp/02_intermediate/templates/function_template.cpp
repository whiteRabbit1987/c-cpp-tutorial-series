#include <iostream>
#include <string>

// Function Template       =   A single function definition written with placeholder type(s) (T).
//                            The compiler automatically generates a specific version of the function 
//                            for each data type it is called with (e.g., one for int, one for float).

// template <typename T>   =   Declares that the following code block is a template and introduces 'T' as 
//                            a placeholder for any data type.

// Type Deduction          =   The compiler figures out the actual type (T) based on the arguments passed 
//                            when the function is called.

// Function Template Definition:
template <typename T>
T find_max(T val1, T val2) {
    return (val1 > val2) ? val1 : val2;
}

int main() {
    
    // --- 1. Integer Usage ---
    // The compiler generates a version: int find_max(int, int)
    int max_int = find_max(10, 50);
    std::cout << "Max Integer: " << max_int << '\n';

    // --- 2. Floating-Point Usage ---
    // The compiler generates a version: float find_max(float, float)
    float max_float = find_max(3.14f, 1.5f);
    std::cout << "Max Float: " << max_float << '\n';

    // --- 3. String Usage ---
    // The compiler generates a version: std::string find_max(std::string, std::string)
    // Comparison works lexicographically (alphabetically)
    std::string max_string = find_max(std::string("Apple"), std::string("Banana"));
    std::cout << "Max String: " << max_string << '\n';

    // --- 4. Explicit Template Argument ---
    // You can explicitly specify the type instead of relying on deduction (optional)
    int max_explicit = find_max<int>(100, 200);
    std::cout << "Max Explicit: " << max_explicit << '\n';

    // NOTE: This generic function assumes the '>' operator is defined for the type T.
    
    return 0;
}