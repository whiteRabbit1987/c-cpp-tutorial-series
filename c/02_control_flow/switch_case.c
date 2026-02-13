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

/*

#include <stdio.h>

void dayOfWeek(int num);

int main() {
    int num = 0;
    printf("Enter a number (1-7): ");
    scanf("%d", &num);
    dayOfWeek(num);
    return 0;
}

void dayOfWeek(int num){
    switch(num){
        case 1: printf("It's Monday");
                break;
        case 2: printf("It's Tuesday");
                break;
        case 3: printf("It's Wednesday");
                break;
        case 4: printf("It's Thursday");
                break;
        case 5: printf("It's Friday");
                break;
        case 6: printf("It's Saturday");
                break;
        case 7: printf("It's Sunday");
                break;
        default: printf("Invalid input!");
    }
}

*/