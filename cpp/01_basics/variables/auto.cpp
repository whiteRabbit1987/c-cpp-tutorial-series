#include <iostream>
#include <typeinfo>

int main(){

    //auto keyword  =  lets the compiler automatically determine the variable's type
    //                 based on the value assigned to it

    auto score = 8;                 //compiler deduces: int
    auto points = 12345678901;      //compiler deduces: long (number too large for int)
    auto height = 6.2f;             //compiler deduces: float (f suffix forces float)
    auto duration = 90.0;           //compiler deduces: double (default for decimals)
    auto is_active = true;          //compiler deduces: bool
    auto initial = 'P';             //compiler deduces: char
    auto title = "Soccer Champions";//compiler deduces: const char*

    //typeid()  =  operator that returns information about a variable's type
    //.name()   =  member function that returns the type name as a string
    //             (often in compiler-specific shorthand form)

    std::cout << "The type of score is " << typeid(score).name() << std::endl;
    std::cout << "The type of points is " << typeid(points).name() << std::endl;
    std::cout << "The type of height is " << typeid(height).name() << std::endl;
    std::cout << "The type of duration is " << typeid(duration).name() << std::endl;
    std::cout << "The type of is_active is " << typeid(is_active).name() << std::endl;
    std::cout << "The type of initial is " << typeid(initial).name() << std::endl;
    std::cout << "The type of title is " << typeid(title).name() << std::endl;

    std::cout << std::endl << std::endl;

    return 0;
}