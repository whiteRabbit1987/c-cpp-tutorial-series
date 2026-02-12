#include <stdio.h>

// if statement =   Do some code if a condition is true.
//                  If the condition is false, don't do it.

int main() {
    
    int age = 0;
    printf("Enter your age: ");
    scanf("%d", &age);

    if(!(age >= 1)){
        age = 0;
    }
    
    if(!age){
        printf("You did not enter a VALID age!");
    } else {
        if(age > 40){
            printf("You are ancient!");
        } else if(age >= 18){
            printf("You are and adult!");
        } else {
            printf("You are a child!");
        }
    }
    return 0;
}