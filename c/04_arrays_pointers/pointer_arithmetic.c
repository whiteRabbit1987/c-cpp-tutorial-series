#include <stdio.h>

int main() {
    int numbers[] = {1, 2, 3};
    int *pNumbers = numbers;

    printf("%d\n", *pNumbers);
    printf("%d\n", *(pNumbers + 1));
    printf("%d\n", *(pNumbers + 2));

    return 0;
}
