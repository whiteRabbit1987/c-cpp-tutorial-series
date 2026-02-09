#include <stdio.h>

int main(){
    // TEMPERATURE CONVERSION
    char choice = '\0';
    float celsius = 0.0f;
    float fahrenheit = 0.0f;

    printf("Temperature conversion program\n");
    printf("C. Celsius to fahrenheit\n");
    printf("F. fahrenheit to Celsius\n");
    printf("Please enter your choice (c or f): ");
    scanf("%c", &choice);

    if(choice == 'c' || choice == 'C'){
        // celsius to fahrenheit
        printf("Enter the temp. in celsius: ");
        scanf("%f", &celsius);
        fahrenheit = (celsius * 9 / 5) + 32;
        printf("%.1f Celsius is equal to %.1f Fahrenheit\n", celsius, fahrenheit);
    } else if (choice == 'f' || choice == 'F'){
        // fahrenheit to celsius
        printf("Enter the temp. in fahrenheit: ");
        scanf("%f", &fahrenheit);
        celsius = (5.0 / 9.0)  * (fahrenheit - 32);
        printf("%.1f Fahrenheit is equal to %.1f Celsius\n", fahrenheit, celsius);
    } else {
        printf("Invalid choice!");
    }

    return 0;
}