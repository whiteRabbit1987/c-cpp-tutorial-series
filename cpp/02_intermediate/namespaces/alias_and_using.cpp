#include <iostream>
#include <string>
#include "MathFunctions.h"

// Namespace Alias               =   Provides a shorter, more convenient nickname for a long or complex namespace name.
//                                   Helps improve code readability without sacrificing scope control.

// using declaration             =   Makes a single namespaced item (like a function or variable) accessible without 
//                                  the namespace prefix (e.g., using std::cout;). Preferred over using directive.

// using directive               =   Imports *all* names from a namespace into the current scope (e.g., using namespace std;).
//                                  Generally discouraged in headers or large scopes due to reintroducing conflicts.

int main() {
    
    // --- Part 1: Namespace Alias Demonstration ---
    
    // Creates a short alias for the Physics3D namespace
    namespace P3D = Physics3D; 

    // Use the alias instead of the full name
    float result_alias = P3D::add(10.0f, 5.0f, 2.0f);
    
    std::cout << "--- Namespace Alias ---" << '\n';
    std::cout << "P3D::add result: " << result_alias << '\n';

    // --- Part 2: using Declaration Demonstration ---
    
    // Makes the 'add' function from Geometry2D directly callable in 'main()'
    using Geometry2D::add; 

    // Call 'add' without the Geometry2D:: prefix.
    // NOTE: This only works for the 2-argument version we specified with 'using'.
    int result_using_decl = add(20, 10); 
    
    std::cout << "\n--- using Declaration (Targeted Import) ---" << '\n';
    std::cout << "Result of plain add(20, 10): " << result_using_decl << '\n';

    // --- Part 3: using Directive Demonstration ---
    
    // Imports ALL names from Physics3D.
    // NOTE: This will not cause an error here because the other 'add' (3-arg) is different.
    using namespace Physics3D; 

    // Call the function directly, as if it were defined in 'main()'
    float result_using_dir = add(1.0f, 2.0f, 3.0f);
    
    std::cout << "\n--- using Directive (Full Import) ---" << '\n';
    std::cout << "Result of plain add(1.0, 2.0, 3.0): " << result_using_dir << '\n';

    return 0;
}