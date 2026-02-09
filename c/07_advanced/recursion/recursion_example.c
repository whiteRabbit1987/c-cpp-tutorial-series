#include <stdio.h>

void hello(int n) {
    if (n > 0) {
        printf("Hello\n");
        hello(n - 1);
    }
}

int main() {
    hello(3);
    return 0;
}
