#include <stdio.h>
#include <stdlib.h>

int main() {
    int *ptr = NULL;
    int n;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    ptr = (int*) malloc(n * sizeof(int));

    if (ptr == NULL) {
        printf("Memory not allocated\n");
        return 0;
    }
    else {
        printf("Memory successfully allocated\n");

        for (int i = 0; i < n; i++) {
            ptr[i] = i + 1;
        }

        printf("The elements are: ");
        for (int i = 0; i < n; i++) {
            printf("%d ", ptr[i]);
        }
    }

    free(ptr);

    return 0;
}
