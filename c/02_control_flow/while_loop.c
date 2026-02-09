#include <stdio.h>
#include <string.h>

int main() {
    
    // while loop   =   Continue some code WHILE the condition remains true
    //                  Condition must be true for us to enter while loop

    // char name[26] = "";
    // printf("What is your name: ");
    // fgets(name, sizeof(name), stdin);

    // while(name){
    //     printf("%s\n", name);
    //     name[strlen(name) - 1] = '\0';
    //     if(strlen(name) < 1){
    //         break;
    //     }
    // }


    char name[25] = "";

    while(strlen(name) <= 1){
        printf("Enter your name: ");
        fgets(name, sizeof(name), stdin);
    }

    printf("Hello, %s", name);


    // int num = 0;

    // do{
    //     printf("Enter a number greater than 0: ");
    //     scanf("%i", &num);
    // }while(num < 0);

    return 0;
}
