#include <iostream>

void printArr(std::string arr[], int size);
void reversed(std::string arr[], int size);

int main(){
    std::string cats[] = {"Simba", "D'mama", "Hicks"};
    int size = sizeof(cats)/sizeof(std::string);

    std::cout << "\nOriginal order: " << std::endl;
    printArr(cats, size);

    reversed(cats, size);

    std::cout << "\nAfter reversing: " << std::endl;
    printArr(cats, size);

    return 0;
}

void printArr(std::string arr[], int size){
    for(int i = 0; i < size; i++){
        std::cout << arr[i] << std::endl;
    }
}

void reversed(std::string arr[], int size){
    std::string temp;
    for(int i = 0; i < size / 2; i++){
        temp = arr[i];
        arr[i] = arr[(size -1) -i];
        arr[(size -1) -i] = temp;
    }
}