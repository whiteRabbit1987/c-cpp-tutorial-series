#include <iostream>

template <typename T>
int findItem(const T arr[], size_t size, T target){
    for(int i = 0; i < size; i++){
        if(target == arr[i]){
            return i;
        }
    }
    return -1;
}

template <typename U>
void showResult(int indexOfItem, U item){
    if(indexOfItem == -1){
        std::cout << "Item '" << item << "' NOT found in the provided array!\n";
    } else {
        std::cout << "Item '" << item << "' found at index: " << indexOfItem << std::endl;
    }
}

int main(){
    
    const std::string StringArray[]{
        "David",
        "James",
        "Phil",
        "Phillip",
        "Frederick"
    };
    size_t StringSize = sizeof(StringArray)/sizeof(std::string);
    std::string StringItem = "Phil";
    int StringIndex = findItem(StringArray, StringSize, StringItem);
    showResult(StringIndex, StringItem);

    const int IntArray[]{5, 33, 65, 4, 3, 66};
    size_t IntSize = sizeof(IntArray)/sizeof(int);
    int IntItem = 7;
    int IntIndex = findItem(IntArray, IntSize, IntItem);
    showResult(IntIndex, IntItem);

    const float FloatArray[]{5.5, 6.7, 112.12, 544.0, 7.0, 4.1};
    size_t FloatSize = sizeof(FloatArray)/sizeof(float);
    float FloatItem = 4.1;
    int FloatIndex = findItem(FloatArray, FloatSize, FloatItem);
    showResult(FloatIndex, FloatItem);

    return 0;
}

