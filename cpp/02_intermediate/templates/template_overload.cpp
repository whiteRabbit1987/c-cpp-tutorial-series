#include <iostream>
#include <cstring> // Required for strcmp

// Function Template       =   The generic function definition.

// Template Overloading    =   Defining a normal, non-templated function that shares the same name 
//                            as the template. The compiler will choose this specific function 
//                            if its arguments match better than the template's arguments.

// Template Specialization =   Providing a unique implementation for a template when the placeholder 'T'
//                            is exactly a specific type (e.g., T is char*).

// --- 1. Generic Function Template ---
template <typename T>
T find_max(T val1, T val2) {
    std::cout << "Using GENERIC TEMPLATE\n";
    return (val1 > val2) ? val1 : val2;
}

// --- 2. Template Specialization for const char* ---
// The compiler uses this specific version when the template is called with C-style strings.
// This is necessary because C++'s '>' operator on const char* compares memory addresses, not string content.
template <>
const char* find_max<const char*>(const char* val1, const char* val2) {
    std::cout << "Using SPECIALIZED TEMPLATE for const char*\n";
    // strcmp returns > 0 if val1 is greater than val2
    return (std::strcmp(val1, val2) > 0) ? val1 : val2;
}

// --- 3. Normal Function Overload (Non-Template) ---
// This overload is provided for the exact type float, but the generic template is usually preferred
// in these simple cases. This mainly demonstrates the compiler's preference rules.
float find_max(float val1, float val2) {
    std::cout << "Using NORMAL OVERLOAD (float)\n";
    return (val1 > val2) ? val1 : val2;
}


int main() {
    
    // 1. Calls the GENERIC TEMPLATE (int version)
    int max_int = find_max(10, 50);
    std::cout << "Max Int: " << max_int << "\n\n";

    // 2. Calls the NORMAL OVERLOAD (float version) 
    // The non-template function is always chosen over the template if the match is exact.
    float max_float = find_max(3.14f, 1.5f);
    std::cout << "Max Float: " << max_float << "\n\n";

    // 3. Calls the SPECIALIZED TEMPLATE (const char* version)
    const char* max_cstr = find_max("Apple", "Banana");
    std::cout << "Max C-String: " << max_cstr << "\n\n";

    return 0;
}