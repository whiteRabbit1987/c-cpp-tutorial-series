#include <stdio.h>

int main() {
    char name[25];

    printf("What's your name?: ");
    fgets(name, 25, stdin);
    name[strcspn(name, "\n")] = 0; // remove trailing newline if any

    printf("Hello %s\n", name);

    return 0;
}
