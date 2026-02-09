#include <stdio.h>
#include <stdlib.h>

struct Node {
    int value;
    struct Node *next;
};

int main() {
    struct Node n1, n2, n3;

    n1.value = 1;
    n2.value = 2;
    n3.value = 3;

    n1.next = &n2;
    n2.next = &n3;
    n3.next = NULL;

    struct Node *current = &n1;

    while(current != NULL) {
        printf("%d\n", current->value);
        current = current->next;
    }

    return 0;
}
