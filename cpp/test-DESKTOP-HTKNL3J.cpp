#include <iostream>

int main(){
    float number = 3.1459f;
    int changed = static_cast<int>(number);
    int again = (int)number;
    int wow = int(number);

    std::cout << wow;

    return 0;
}