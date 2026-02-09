// Memory on demand in C++
// C++ allows us to control exactly when memory is allocated and freed
// using the keywords: new and delete
// This is useful when the size of the data is not known at compile time
// or when we want precise control over memory usage.

#include <iostream>


int main(){

    int *squares = new int[6];
    for(int i = 0; i < 6; i++){
        squares[i] = i * i;
    }
    for(int i = 0; i < 6; i++){
        std::cout << squares[i] << "\n";
    }

    delete [] squares; //Use delete[] to free memory from an array; plain delete is only for single objects

    return 0;
}



// #include <iostream>

// int main() {

//     // -----------------------------
//     // Single variable allocation
//     // -----------------------------
    
//     // new requests memory for a single integer on the heap
//     int *count = new int;  // memory not initialized (contains garbage)
    
//     *count = 42; // assign a value to the allocated memory

//     std::cout << "Value of count: " << *count << '\n';

//     // delete frees memory previously allocated by new
//     delete count;  // prevents memory leaks

//     // -----------------------------
//     // Array allocation
//     // -----------------------------
    
//     // new requests memory for an array of 20 floats on the heap
//     float *array = new float[20]; // memory not initialized

//     // initialize array manually
//     for(int i = 0; i < 20; i++){
//         array[i] = i * 1.5f; // assign values
//     }

//     std::cout << "Array values: ";
//     for(int i = 0; i < 20; i++){
//         std::cout << array[i] << " ";
//     }
//     std::cout << '\n';

//     // delete[] frees the memory allocated for arrays
//     delete[] array; // important: use delete[] for arrays

//     return 0;
// }