#include <stdio.h>

int main() {
    int age = 21;
    int *pAge = &age;

    printf("Address of age: %p\n", &age);
    printf("Value of pAge: %p\n", pAge);
    printf("Value pointed to by pAge: %d\n", *pAge);

    return 0;
}
