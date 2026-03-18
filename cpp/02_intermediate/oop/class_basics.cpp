// class fundamentals combined demo
// ctor / dtor        = automatic; compiler generates defaults if you don't declare them
// user-defined ctor  = initialize members or allocate resources
// user-defined dtor  = required when class owns dynamic memory (RAII cleanup)
// getters/setters    = control access to private data (encapsulation)
// const methods      = promise not to modify object state
// copy ctor          = defines how object is copied (deep copy if owning resources)
// static member      = shared across all instances; exists independently of objects
// inheritance        = derived class extends base class behavior

#include <iostream>
#include <string>

class Monster {
public:
    // user-defined constructor
    Monster(const std::string& n, int hp)
        : name(n), health(hp)
    {
        data = new int[health]; 
        std::cout << "[CTOR] Monster '" << name 
                  << "' created with " << health << " HP\n";
    }

    // copy constructor (deep copy)
    Monster(const Monster& other)
        : name(other.name), health(other.health)
    {
        data = new int[health]; 
        std::cout << "[COPY CTOR] Copied Monster '" << name << "'\n";
    }

    // destructor
    ~Monster() {
        delete[] data;
        std::cout << "[DTOR] Monster '" << name << "' destroyed\n";
    }

    // getter (const-correct)
    int getHealth() const {
        return health; // const method → cannot modify members
    }

    // setter
    void setHealth(int hp) {
        health = hp;
    }

    // static member function
    static int getMonsterCount() {
        return monsterCount;
    }

protected:
    std::string name;
    int health;
    int* data;

    static int monsterCount;
};

// static member definition
int Monster::monsterCount = 0;

// derived class
class Boss : public Monster {
public:
    Boss(const std::string& n, int hp, int dmg)
        : Monster(n, hp), damage(dmg)
    {
        std::cout << "[CTOR] Boss '" << name 
                  << "' with damage " << damage << "\n";
    }

    int getDamage() const {
        return damage;
    }

private:
    int damage;
};

int main() {
    std::cout << "Game start\n";

    Monster goblin("Goblin", 50);
    std::cout << "Goblin HP: " << goblin.getHealth() << "\n";

    goblin.setHealth(60);
    std::cout << "Goblin HP after heal: " << goblin.getHealth() << "\n";

    Monster copyGoblin = goblin; // invokes copy constructor

    Boss ogreBoss("Ogre King", 300, 40);
    std::cout << "Boss damage: " << ogreBoss.getDamage() << "\n";

    std::cout << "Game ending...\n";
    return 0;
}
