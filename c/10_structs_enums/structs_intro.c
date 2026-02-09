#include <stdio.h>

struct Player {
    char name[12];
    int score;
};

int main() {
    struct Player player1 = {"Bro", 4};
    struct Player player2 = {"Code", 5};

    printf("%s\n", player1.name);
    printf("%d\n", player1.score);

    printf("%s\n", player2.name);
    printf("%d\n", player2.score);

    return 0;
}
