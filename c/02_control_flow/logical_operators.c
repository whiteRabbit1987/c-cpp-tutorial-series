#include <stdio.h>
#include <stdbool.h>

int main(){

    // logical operators    =   Used to combine or modify boolean expressions.
    //                          && = AND
    //                          || = OR
    //                          !  = NOT

    // int temp = -10;

    // if(temp > 0 && temp < 30){
    //     printf("The temperature is good");
    // } else {
    //     printf("Teh temperature is bad!");
    // }

    bool isSunny = true;

    if(!isSunny){
        printf("It is SUNNY outside.");
    } else {
        printf("It is CLOUDY outside.");
    }

    return 0;
}