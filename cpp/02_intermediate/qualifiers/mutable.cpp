#include <iostream>

// mutable members       = allows modification of class members even if object is const
//                         useful for internal state that doesn't affect external behavior

class Player {
public:
    void updateScore() const {
        ++score; // mutable allows this even in const function
    }

    int getScore() const {
        return score;
    }

private:
    mutable int score = 0;
};

int main() {
    const Player p;
    p.updateScore();
    std::cout << "Player score: " << p.getScore() << std::endl;

    return 0;
}
