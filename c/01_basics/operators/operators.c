#include <stdio.h>

int main() {
    int x = 5;
    int y = 2;

    int z = x + y;
    int a = x - y;
    int b = x * y;
    int c = x / y;
    int d = x % y;

    printf("%d\n", z);
    printf("%d\n", a);
    printf("%d\n", b);
    printf("%d\n", c);
    printf("%d\n", d);

    x++;
    y--;

    printf("%d\n", x);
    printf("%d\n", y);

    return 0;
}
