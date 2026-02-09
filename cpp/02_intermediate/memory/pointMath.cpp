#include <iostream>

// pointer fundamentals    = Pointers can reference elements inside an array,
//                           and pointer arithmetic allows moving through
//                           the array by computing new positions.
//
// array size technique   =  sizeof(array) / sizeof(element_type) gives the
//                           total number of elements in a fixed-size array.
//
// indexing with pointers =  Calculating an index and taking its address
//                           lets us directly point to specific positions
//                           (first, middle, last) without loops.
//
// pointer distance        =  Subtracting two pointers yields the number of
//                           elements between them, enabling relative jumps
//                           to new array positions.
//
// useful for             =  Understanding how arrays map to memory,
//                           navigating arrays without indexing syntax,
//                           and learning low-level pointer behavior.

int main(){

    int numbers[] = {10, 20, 30, 40, 50};

    int* firstPtr = numbers;  // points to first element
    int* middlePtr = numbers + (sizeof(numbers)/sizeof(int))/2;  // points to middle element
    int* lastPtr = numbers + (sizeof(numbers)/sizeof(int)) - 1; // points to last element

    std::cout << "First: " << *firstPtr << std::endl;
    std::cout << "Middle: " << *middlePtr << std::endl;
    std::cout << "Last: " << *lastPtr << std::endl;

    // Pointer arithmetic: move one forward from middle
    int* nextPtr = middlePtr + 1;
    std::cout << "Next after middle: " << *nextPtr << std::endl;

    // Pointer distance
    std::ptrdiff_t dist = lastPtr - firstPtr;
    std::cout << "Distance from first to last: " << dist << std::endl;

    return 0;
}
