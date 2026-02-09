#include <stdio.h>
#include <string.h>
#include <stdbool.h>

bool ageCheck(int age){
    if(age>=18){
        return true;
    }
    return false;
}

int main(){

    int age = 0;
    printf("Enter your age: ");
    scanf("%i", &age);

    if(ageCheck(age)){
        printf("You are old enough to enter.");
    } else {
        printf("You are too young to enter.");
    }
    return 0;
}

// return   =   returns a value back to where you call a function



// double squared(double x){
//     return x * x;
// }


// int main() {
    
//     double num = 0.0;
//     double result = 0.0;
//     printf("Enter a number: ");
//     scanf("%lf", &num);
//     result = squared(num);
//     printf("The number you entered squared is: %.2lf", result);

//     return 0;
// }


// char * greeting(const char name[]){
//     static char buffer[100]; // static keeps it valid after the function returns
//     snprintf(buffer, sizeof(buffer), "Hello, %s", name);
//     return buffer;
// }

// int main(){
//     char name[25] = "";
//     printf("What is your name: ");
//     if(fgets(name, sizeof(name), stdin)){
//         name[strcspn(name, "\n")] = '\0'; // safer way to strip newline
//         printf("%s\n", greeting(name));
//     }
//     return 0;
// }



