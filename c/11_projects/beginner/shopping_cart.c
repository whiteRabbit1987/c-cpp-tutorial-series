/*
SHOPPING CART PROGRAM
*/
#include <stdio.h>
#include <string.h>

int main(){
    char item[50] = "";
    float price = 0.0f;
    int quantity = 0;
    char currency = '$';
    float total = 0.0f;

    printf("What item would you like to buy?: ");
    fgets(item, sizeof(item), stdin); // reads full line including enter/new line
    item[strlen(item) -1] = '\0'; // removes new line character

    printf("What is the price for each?: ");
    scanf("%f", &price);
    
    printf("How many would you like?: ");
    scanf("%d", &quantity);

    total = price * quantity;
    
    printf("\nYou have bought %d %s's\n", quantity, item);
    printf("Your total is %c%.2f\n", currency, total);


    return 0;
}
    