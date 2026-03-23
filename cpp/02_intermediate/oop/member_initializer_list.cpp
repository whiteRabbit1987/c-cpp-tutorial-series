// member initializer list fundamentals
// purpose               = initialize members before constructor body runs
// syntax                = ClassName() : member(value), member2(value2) {}
// required for          = const members, reference members, and classes without default ctors
// performance benefit   = avoids default construction + reassignment
// initialization order  = follows declaration order in class, NOT the order in the initializer list
// best practice         = always use initializer lists for simple member initialization

#include <iostream>
#include <string>

class Player {
public:
    // member initializer list initializes name and health BEFORE the constructor body executes
    Player(const std::string& n, int hp)
        : name(n), health(hp)   // initialization happens here
    {
        std::cout << "Player constructed: " << name << " with HP " << health << "\n";
    }

    // const member must be initialized in initializer list (cannot assign in constructor body)
    Player(int hp)
        : name("Unknown"), health(hp)
    {}

    // display is const because it does not modify the object
    void display() const {
        std::cout << "Player: " << name << " | HP: " << health << "\n";
    }

private:
    std::string name;  // initialized via initializer list
    int health;        // initialized via initializer list
};

class Enemy {
public:
    // demonstrates initialization order rule
    // even though health is listed first, name is initialized first
    Enemy(const std::string& n, int hp)
        : health(hp), name(n)   // order here does NOT matter
    {
        std::cout << "Enemy constructed: " << name << " with HP " << health << "\n";
    }

private:
    std::string name;  // initialized first (declared first)
    int health;        // initialized second
};

int main() {
    Player p1("Arthur", 100);
    p1.display();

    Enemy e1("Goblin", 30);
    e1.display(); // error: Enemy has no display(), intentional for this example

    return 0;
}
