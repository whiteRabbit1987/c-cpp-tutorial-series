#include <iostream>

int main(){

    const size_t rows = 3;
    const size_t cols = 4;
    int nums[rows][cols] = {
        {111, 121, 32, 43},
        {25, 617, 317, 38},
        {13, 22, 44, 3}
    };
    int max = -9999;


    for(int row = 0; row < rows; row++){
        for(int col = 0; col < cols; col++){
            if(nums[row][col] > max){
                max = nums[row][col];
            }
        }
    }
    std::cout << "The max number is: " << max;
    return 0;
}