#include <stdio.h>

int main() {
    
    // switch = An alternative to using many if-else statements
    //          More effective w/ fixed integer values

    char input = '\0';

    printf("Enter yes or no: ");
    scanf("%c", &input);

    switch(input){
        case 'y': 
        case 'Y':
            printf("You entered yes");
            break;
        case 'n':
        case 'N':
            printf("You entered no");
            break;
        default:
            printf("invalid input");
            break;
    }


    return 0;
}
