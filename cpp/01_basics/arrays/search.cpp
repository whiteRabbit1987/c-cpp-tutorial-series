#include <iostream>

int searchArray(int array[], int size, int el);

int main(){
    int nums[] = {5, 15, 25, 35, 40};
    int size = sizeof(nums)/sizeof(int);
    int element;
    int index;

    std::cout << "Enter number to search for: ";
    std::cin >> element;

    index = searchArray(nums, size, element);
    if(index != -1){
        std::cout << "Found element at index of: " << index << '\n';
    } else {
        std::cout << "Element is not in the array!";
    }
    return 0;
}
int searchArray(int array[], int size, int el){
    for(int i = 0; i < size; i++){
        if(array[i] == el){
            return i;
        }
    }
    return -1;
}