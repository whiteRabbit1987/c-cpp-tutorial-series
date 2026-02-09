#include <stdio.h>
#include <string.h>

int main() {
    
    char name[50] = "";
    printf("Enter you name: ");
    fgets(name, sizeof(name), stdin);
    name[strlen(name) -1] = '\0';

    if(strlen(name) ==  0){
        printf("You did not enter a name!");
    } else {
        printf("Hello %s", name);
    }

    return 0;
}








    // if statement = Do some code if a condition is true.
    //                If the contidion is false, don't do it.

    // int age = 0;
    
    // printf("Enter you age: ");
    // scanf("%i", &age);


    // if (age >= 65){
    //     printf("You are a senior");
    // }
    // else if(age >= 18){
    //     printf("You are an adult");
    // } else if (age < 0){
    //     printf("You haven't been born yet");
    // } else {
    //     printf("You are a child!");
    // }