#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){

    // Pseudo-random    =   Appear random but are determined by a
    //                      mathmatical formula that uses a seed value
    //                      to generate a predictable sequence of numbers.
    //                      advanced: Mersenne Twister or /dev/random (hardware entropy)

    srand(time(0));

    int min = 50;
    int max = 100;

    int randomNum = (rand() % (max - min)) + min;
    printf("Random number: %i\n", randomNum);

    printf("Max possible: %i", RAND_MAX);

    return 0;
}