#include <stdio.h>
#include <string.h>

int main(){
    
    int age = 0;
    float gpa = 0.0f;
    char grade = '\0';
    char name[30] = "";

    printf("Enter your age: ");
    scanf("%d", &age);

    printf("Enter your gpa: ");
    scanf("%f", &gpa);
    
    printf("Enter your grade: " );
    scanf(" %c", &grade); // space before format specifier clears buffer

    getchar(); // clears input buffer
    printf("Enter your first name: ");
    fgets(name, sizeof(name), stdin); // read full line including enter
    name[strlen(name) -1] = '\0';

    printf("%s\n", name);
    printf("%d\n", age);
    printf("%.2f\n", gpa);
    printf("%c\n", grade);
 

    return 0;
}
