#include <iostream>

// Jagged Array           =   A multi-dimensional array where the sub-arrays (rows) can have different lengths.
//                           This is achieved using the pointer-to-pointer technique (int **arr).

// Triangular Matrices    =   Jagged arrays are specifically useful for representing structures like triangular 
//                           matrices, where the length of each row depends on its index (r + 1).

// Dynamic Allocation    =   The array is allocated in two stages: first the array of row pointers (int * [rows]),
//                           then each row array (new int[r + 1]) separately.

int main(void) {
    int rows = 5;
    // The columns variable is not strictly needed for the jagged allocation, but often used for bounds
    int ** arr; 
    
    // allocate the array of row pointers
    arr = new int * [rows];
    
    // allocate and initialize each row dynamically based on the row index (r + 1)
    for (int r = 0; r < rows; r++) {
        // Each row gets a size of (r + 1)
        arr[r] = new int[r + 1]; 
        
        for (int c = 0; c <= r; c++)
            arr[r][c] = (r + 1) * 10 + c + 1; // Assigning data
    }
    
    // print the array
    for (int r = 0; r < rows; r++) {
        for (int c = 0; c <= r; c++)
            std::cout << arr[r][c] << " ";
        std::cout << std::endl;
    }
    
    // free the array (must be done in reverse order of allocation)
    for (int r = 0; r < rows; r++)
        delete[] arr[r];
        
    delete[] arr;
    
    return 0;
}