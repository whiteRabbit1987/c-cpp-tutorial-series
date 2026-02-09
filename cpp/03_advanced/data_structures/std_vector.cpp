#include <iostream>
#include <vector> // Required header for std::vector
#include <string>

// std::vector            =   A sequence container that manages a dynamic array.
//                           Unlike static arrays, its size can change during runtime.

// Dynamic Size           =   Vector handles memory management automatically; when the array runs out
//                           of space, it automatically allocates a larger block of memory and copies
//                           the elements over.

// push_back()            =   A method used to add an element to the end of the vector, automatically
//                           increasing the size of the container.

// size() method          =   Returns the current number of elements stored in the vector.

int main(){

    // Initialization using list initialization {}
    std::vector<int> numbers = {10, 20, 30};

    std::cout << "--- Initial Vector ---" << '\n';
    std::cout << "Initial size: " << numbers.size() << '\n';
    std::cout << "Element at index 1: " << numbers[1] << '\n';

    // Add elements dynamically
    numbers.push_back(40);
    numbers.push_back(50);
    
    // Demonstrate dynamic size change
    std::cout << "\n--- Vector After push_back ---" << '\n';
    std::cout << "New size: " << numbers.size() << '\n';
    std::cout << "Last element: " << numbers[4] << '\n'; 

    // Demonstration with a different data type
    std::vector<std::string> names;
    names.push_back("Alice");
    names.push_back("Bob");

    std::cout << "\n--- String Vector ---" << '\n';
    std::cout << "First name: " << names[0] << '\n';

    return 0;
}