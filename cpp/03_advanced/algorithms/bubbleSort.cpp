#include <iostream>

// bubble sort =   a simple sorting technique that repeatedly compares neighboring elements
//                 and swaps them if they are out of order, looping until no swaps occur
//                 (using a 'swapped' flag to detect when the array is sorted)
//
// used for:       small datasets, teaching basic sorting concepts, easy-to-read examples,
//                 situations where simplicity matters more than performance
//
// not used for:   large datasets, performance-critical applications, real-time systems,
//                 or anything requiring efficient O(n log n) sorting

int main(void) {
using std::cout, std::cin, std::endl;

    int * numbers{nullptr}, how_many_numbers{0}, aux{0};
    bool swapped{false};

    // Get the size of the array
    cout << "How many numbers are you going to sort?";
    cin >> how_many_numbers;
    if(how_many_numbers <= 0 || how_many_numbers > 1000000){
        cout << "Are you kidding?" << endl;
        return 1;
    }

    // Assign the array size and contents
    numbers = new int[how_many_numbers];
    for(int i = 0; i < how_many_numbers; i++){
        cout << "Enter number #" << i + 1 << ": ";
        cin >> numbers[i];
    }

    // Bubble sort logic start
    do{
        swapped = false;
        for(int i = 0; i < how_many_numbers - 1; i++){
            if(numbers[i] > numbers[i+1]){
                swapped = true;
                aux = numbers[i];
                numbers[i] = numbers[i+1];
                numbers[i+1] = aux;
            }
        }
    } while(swapped);
    // Bubble sort logic end


    cout << endl << "The sorted array:" << endl;
    for(int i = 0; i < how_many_numbers; i++){
        cout << numbers[i] << " ";
    }
    cout << endl;

    // Don't forget to clean the heap
    // Free the dynamically allocated array to avoid memory leaks
    delete [] numbers;

    return 0;
}