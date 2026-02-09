#include <stdio.h>
#include <stdbool.h>

    // variable = A reusable container for a value.
    //            Behaves as if it were the value it contians.

    // int      =   whole numbers (4 bytes in modern systems)
    // float    =   single-precision decimal number (4 bytes)
    // double   =   double-precision decimal number (8 bytes)
    // char     =   single character (1 byte)
    // char[]   =   array of characters (size varies)
    // bool     =   true false (1 byte, requires <stdbool.h>) 

int main() {

    int age; // declaration
    age = 25; // initialization
    float gpa = 2.5; //declaration + initialization
    char grade = 'C';
    char name[] = "David";
    double pi = 3.14159265358979;

    printf("You are %d years old\n", age);
    printf("Your gpa is %.2f\n", gpa);
    printf("Your grade is %c\n", grade);
    printf("Hello %s\n", name);
    printf("The value of pi is: %.15lf\n", pi);

    bool isOnline = true;

    if(isOnline){
        printf("You are ONLINE");
    }
    else{
        printf("You are OFFLINE");
    }
    
    return 0;
}
