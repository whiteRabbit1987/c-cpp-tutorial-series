#include <iostream>

// static class members  = shared across all objects of the class
//                         common data/state accessible without creating an instance

class Enemy {
public:
    static int enemyCount;

    Enemy() {
        ++enemyCount;
    }

    static void showEnemyCount() {
        std::cout << "Total Enemies: " << enemyCount << std::endl;
    }
};

int Enemy::enemyCount = 0;

int main() {
    Enemy goblin;
    Enemy orc;
    Enemy troll;

    Enemy::showEnemyCount();
    return 0;
}
