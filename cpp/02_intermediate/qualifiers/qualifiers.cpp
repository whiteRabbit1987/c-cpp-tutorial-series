#include <iostream>
#include <string>

// C++ Qualifiers Example
// const      = values that cannot be modified
// volatile   = tells compiler variable may change anytime (used in multithread/hardware)
// mutable    = allows modification of member even in const object
// inline     = suggests compiler to insert function code at call site
// constexpr  = evaluated at compile time if possible
// static     = preserves value across function calls or shared across class instances

class Player {
public:
    Player(const std::string& n) : name(n) {}

    void showName() const {
        // const member function cannot modify non-mutable members
        std::cout << "Player Name: " << name << std::endl;
        ++score; // mutable allows this
    }

    int getScore() const { return score; }

private:
    std::string name;
    mutable int score = 0; // mutable allows modification in const function
};

// inline function example
inline int calculateDamage(int base, int modifier) {
    return base + modifier;
}

// constexpr function example
constexpr int maxHealth(int level) {
    return 100 + level * 10;
}

// static function / variable example
void generateID() {
    static int id = 0; // retains value across calls
    ++id;
    std::cout << "Generated ID: " << id << std::endl;
}

int main() {
    // const variable example
    const int maxLevel = 50;

    Player hero("Artemis");
    hero.showName();
    hero.showName(); // mutable score increments even though showName is const
    std::cout << "Player Score after 2 views: " << hero.getScore() << std::endl;

    std::cout << "Damage dealt: " << calculateDamage(30, 15) << std::endl;
    std::cout << "Max health at level 5: " << maxHealth(5) << std::endl;

    generateID(); // 1
    generateID(); // 2
    generateID(); // 3

    std::cout << "Maximum level allowed: " << maxLevel << std::endl;

    // volatile example (illustrative only, not really changing externally here)
    volatile int enemyStatus = 1;
    std::cout << "Enemy status: " << enemyStatus << std::endl;

    return 0;
}
