// const correctness fundamentals
// const variable        = value cannot change after initialization
// const reference       = reference cannot modify the referred object
// const pointer         = pointer itself or the pointee can be const (low/high-level const)
// const member function = promises not to modify object state
// const object          = can only call const member functions
// purpose               = safety, clarity, prevents accidental modification

#include <iostream>
#include <string>

class Player {
public:
    Player(const std::string& n, int hp)
        : name(n), health(hp)
    {}

    // const member function → cannot modify name or health
    // allows calling this on const Player objects
    void display() const {
        std::cout << "Player: " << name << " | HP: " << health << "\n";
        // name = "X";   // ❌ error: cannot modify inside const function
    }

    // getter should be const because it does not modify the object
    int getHealth() const {
        return health;
    }

    // setter is non-const because it modifies the object
    void setHealth(int hp) {
        health = hp;
    }

private:
    std::string name;
    int health;
};

int main() {
    // const variable
    const int maxHP = 100;
    // maxHP = 50; // ❌ error

    // const reference → cannot modify through ref
    int value = 10;
    const int& ref = value;
    // ref = 20; // ❌ error

    // const pointer to non-const data
    int x = 5;
    int* const ptr = &x; // pointer cannot change, value can
    *ptr = 20;           // ✔ allowed
    // ptr = &maxHP;     // ❌ pointer is const

    // pointer to const data
    const int* p2 = &x;  // data cannot change, pointer can
    // *p2 = 30;         // ❌ cannot modify through pointer
    p2 = &maxHP;         // ✔ pointer can change

    // const object → can only call const member functions
    const Player p("Arthur", 80);
    p.display();         // ✔ allowed (display() is const)
    // p.setHealth(50);  // ❌ error: cannot call non-const function

    Player p2("Lancelot", 90);
    p2.setHealth(95);    // ✔ allowed
    p2.display();

    return 0;
}
