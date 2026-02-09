#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *pF = fopen("test.txt", "r");
    char buffer[255];

    if (pF == NULL) {
        printf("Unable to open file\n");
        return 1;
    }

    while(fgets(buffer, 255, pF) != NULL) {
        printf("%s", buffer);
    }

    fclose(pF);

    return 0;
}
