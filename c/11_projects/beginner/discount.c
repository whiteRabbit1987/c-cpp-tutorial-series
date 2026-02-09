#include <stdio.h>
#include <stdbool.h>

int main(){

    float price = 10.00;
    //float discount = 0.0f;
    bool isStudent = true; // 10% discount
    bool isSenior = false; // 20% discount


    if(isStudent){
        if(isSenior){
            printf("You get a student discount of 10%\n");
            printf("You get a senior discount of %20\n");
            price *= 0.7;
        } else {
            printf("You get a student discount of 10%\n");
            price *= 0.9;
        }
    } else {
        if(isSenior){
            printf("You get a senior discount of %20\n");
            price *= 0.8;
        }
    }

    printf("The price of a ticket is: $%.2f\n", price);


    // if(isSenior && isStudent){
    //     printf("You get a 30%% discount.\n");
    //     discount = .3;
    //     price -= price * discount;
    //     printf("Your discounted price is : %.2f", price);
    // }
    // else if(isStudent){
    //     printf("You get a 10%% discount.\n");
    //     discount = .1;
    //     price -= price * discount;
    //     printf("Your discounted price is : %.2f", price);
    // }
    // else if(isSenior){
    //     printf("You get a 20%% discount.\n");
    //     discount = .2;
    //     price -= price * discount;
    //     printf("Your discounted price is : %.2f", price);
    // }
    // else {
    //     printf("No discount!\n");
    //     printf("you pay now %.2f", price);
    // }

    return 0;
}