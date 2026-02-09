#ifndef CLASSTEMPLATE_H
#define CLASSTEMPLATE_H

// Class Template          =   A blueprint for creating a class where one or more of its member types 
//                            are generic (T, U).

// Generic Pair Class      =   A simple example demonstrating how a single class definition can hold
//                            any combination of data types (e.g., a pair of int and string, or float and bool).

// template <typename T, U> =   Declares the class as a template and introduces two independent type parameters, T and U.

template <typename T, typename U>
class Pair {
public:
    T first;
    U second;

    // Constructor definition inside the class for simplicity
    Pair(T f, U s) : first(f), second(s) {}

    // A simple method to swap the values (must be careful with types T and U)
    void swap_values() {
        // NOTE: Since T and U might be different types, we cannot swap them directly 
        // without a temporary variable of the correct type, or specialized code.
        // For simplicity, we just print the current state.
        std::cout << "Attempting to operate on T (" << first << ") and U (" << second << ")\n";
    }

    // A helper method for printing the content
    void print_values() const;
};

// NOTE ON IMPLEMENTATION: 
// It is common practice in C++ to define function template and class template methods 
// entirely within the header file. This is because the compiler needs the full template 
// definition available when instantiating the specific type (e.g., Pair<int, float>).

// Implementation of a method defined outside the class body
template <typename T, typename U>
void Pair<T, U>::print_values() const {
    std::cout << "First (" << typeid(T).name() << "): " << first 
              << ", Second (" << typeid(U).name() << "): " << second << "\n";
}

#endif // CLASSTEMPLATE_H