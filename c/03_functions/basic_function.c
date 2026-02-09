#include <stdio.h>
#include <string.h>

// function =   A reusable section of code that can be invoked "called"
//              Arguments can be sent to a function so that it can use them

void birthday(char name[], int age) {
    printf("Happy Birthday to you!\n");
    printf("Happy Birthday to you!\n");
    printf("Happy Birthday dear %s!\n", name);
    printf("Happy Birthday to you!\n");
    printf("You are now %i years  old\n", age + 1);
}

int main() {

    char name[25] = "";
    int age = 0;
    printf("What is your name: ");
    fgets(name, sizeof(name), stdin);
    name[strlen(name) - 1] = '\0';

    printf("How old are you: ");
    scanf("%i", &age);

    birthday(name, age);

    return 0;
}
