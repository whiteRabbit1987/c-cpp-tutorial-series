#include <stdio.h>
#include <string.h>

int main() {
    char string1[] = "Bro";
    char string2[] = "Code";

    // Concatenate strings
    strcat(string1, string2);
    printf("%s\n", string1);

    // Copy string
    strcpy(string1, string2);
    printf("%s\n", string1);

    // Get string length
    int length = strlen(string1);
    printf("Length: %d\n", length);

    return 0;
}
