#include <stdio.h>

// ternary operator:    ? returns the first result if condition is true
//                      otherwise it will return the second result
//                      (condition/expression) ? variable : variable

int main() {

    int a = 0;
    int b = 0;

    printf("###\tNumber comparsision program\t###\n");
    printf("###\tEnter two number to compare\t###\n");
    printf("Enter number #1: ");
    scanf("%d", &a);
    printf("Enter number #2: ");
    scanf("%d", &b);

    printf("%d is bigger than %d", (a > b ? a : b), (a > b ? b : a));

    return 0;
}
