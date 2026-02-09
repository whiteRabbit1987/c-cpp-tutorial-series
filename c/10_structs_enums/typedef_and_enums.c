#include <stdio.h>

typedef struct {
    char name[12];
    int score;
} Player;

enum Day {Sun = 1, Mon, Tue, Wed, Thu, Fri, Sat};

int main() {
    Player player = {"Bro", 5};

    printf("%s\n", player.name);
    printf("%d\n", player.score);

    enum Day today = Wed;
    printf("Today is day number: %d\n", today);

    return 0;
}
