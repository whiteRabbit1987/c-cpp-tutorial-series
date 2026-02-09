#include <iostream>
#include "MathFunctions.h"

// Scope Resolution Operator (::) =  Used in the calling file (main) to explicitly tell the compiler
//                                  which namespace a function belongs to, preventing an ambiguity error.

// Ambiguity Error                =   If you try to call 'add(5, 3)' without a namespace qualifier, 
//                                  the compiler would not know if you mean Geometry2D::add or Physics3D::add.

int main() {
    
    // Geometry2D::add(a, b) =  Calling the 2-argument integer addition function
    int result_2d = Geometry2D::add(10, 5);

    // Physics3D::add(a, b, c) =  Calling the 3-argument floating-point addition function
    float result_3d = Physics3D::add(1.5f, 2.0f, 3.5f);

    std::cout << "--- Namespace Collision Resolution ---" << '\n';
    
    // Explicitly calling the 2D function
    std::cout << "2D Result (Geometry2D::add): " << result_2d << '\n';

    // Explicitly calling the 3D function
    std::cout << "3D Result (Physics3D::add): " << result_3d << '\n';

    // NOTE: If both 'add' functions had the same signature (e.g., int add(int, int)), 
    // trying to call 'add(10, 5)' here would result in a compilation error due to ambiguity.
    
    return 0;
}