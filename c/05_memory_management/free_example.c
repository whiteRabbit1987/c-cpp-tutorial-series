#include <stdio.h>
#include <stdlib.h>

int main() {
    int *ptr = NULL;
    int n = 5;

    ptr = (int*) malloc(n * sizeof(int));

    if (ptr == NULL) {
        printf("Memory not allocated\n");
        return 0;
    }

    for (int i = 0; i < n; i++) {
        ptr[i] = i;
    }

    printf("Before free: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", ptr[i]);
    }
    printf("\n");

    free(ptr);

    ptr = NULL; // good practice after free()

    return 0;
}
