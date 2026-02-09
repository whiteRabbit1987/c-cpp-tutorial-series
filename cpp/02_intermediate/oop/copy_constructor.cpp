// A copy constructor creates a new object by using another object of the same class.
// It has a single parameter: a reference to the same class, usually marked const.
// It is invoked automatically during copy-initialization (e.g., Class b = a).
// If no copy constructor is defined, the compiler generates a default one that
// performs a member-by-member (shallow) copy.
// A user-defined copy constructor may modify or transform the copied data.
// Copy constructors are also invoked when objects are passed by value to functions.

#include <iostream>

class Class1 {
public:
    Class1(int val) { value = val; }

    // Custom copy constructor modifies the copied value
    Class1(const Class1& source) { value = source.value + 100; }

    int value;
};

class Class2 {
public:
    Class2(int val) { value = val; }
    // No copy constructor → compiler-generated member-wise copy is used

    int value;
};

int main(void) {
    Class1 object11(100), object12 = object11;
    Class2 object21(200), object22 = object21;

    std::cout << object12.value << std::endl;
    std::cout << object22.value << std::endl;

    return 0;
}
