#include <stdio.h>

int main(){
    // Calculator Program

    double num1 = 0.0;
    double num2 = 0.0;
    char operator = '\0';
    double result = 0.0;

    printf("*******************************************\n");
    printf("Simple 2 operand only Calculator programm\n");
    printf("*******************************************\n");

    printf("Enter the first number: ");
    scanf("%lf", &num1);
    getchar();
    printf("Enter the operator (+-*/): ");
    scanf("%c", &operator);
    printf("Enter the second number: ");
    scanf("%lf", &num2);

    switch(operator){
        case '+':
            result = num1 + num2;
            break;
        case '-':
            result = num1 - num2;
            break;
        case '*':
            result = num1 * num2;
            break;
        case '/':
            if(num2 == 0){
                printf("Can't divide by zero!");
                return 1;
            } else {
                result = num1 / num2;
            }
            break;
        default:
            printf("Invalid input detected!\n");
            return 1;
    }
    printf("The result of %.2f %c %.2f is %.2f", num1, operator, num2, result);

    return 0;
}