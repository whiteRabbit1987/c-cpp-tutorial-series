#include <iostream>
#include <ctime>

int main(){

    // pseudo-random    =   NOT truly random (but close)
    //                      srand(time(NULL));
    //                      int num1 = (rand() % 6) + 1;

    srand(time(NULL));
    int randNum = (rand() % 6) + 1;

    switch(randNum){
        case 1: std::cout << "You win a bumber sticker!\n";
                break;
        case 2: std::cout << "You win a t-shirt!\n";
                break;
        case 3: std::cout << "You win a free lunch!\n";
                break;
        case 4: std::cout << "You win a gift card!\n";
                break;
        case 5: std::cout << "You win concert tickets!\n";
                break;
        case 6: std::cout << "You loose!\n";
                break;
    }

    return 0;
}
































 