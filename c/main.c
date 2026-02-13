#include <stdio.h>

// Calculator Program

int main() {

    char operator = '\0';
    double num1 = 0.0;
    double num2 = 0.0;
    double result = 0.0;

    printf("################################################\n");
    printf("############### CLI Calculator #################\n");
    printf("################################################\n");
    printf("\nEnter the first number: ");
    scanf("%lf", &num1);
    printf("Enter an operator (+-/*): ");
    scanf(" %c", &operator);
    printf("Enter the second number: ");
    scanf("%lf", &num2);

    switch(operator){
        case '+':   result = num1 + num2;
                    break;
        case '-':   result = num1 - num2;
                    break;
        case '*':   result = num1 * num2;
                    break;
        case '/':   if(num2 == 0) { 
                        printf("Invalid input!");
                        return 1;
                    }  
                    result = num1 / num2;
                    break;
        default:    printf("Invalid input!");
                    return 1;
    }

    printf("\n%.2lf %c %.2lf = %.2lf", num1, operator, num2, result);

    return 0;
}
