// inheritance and polymorphism fundamentals
// inheritance           = create hierarchies; derived class reuses and extends base class
// polymorphism          = call correct overridden function at runtime through base pointer
// virtual function      = enables dynamic dispatch; derived class can override behavior
// override keyword      = ensures function truly overrides a virtual base function
// protected members     = accessible to derived classes but hidden from outside
// abstract class        = contains at least one pure virtual function; cannot be instantiated
// pure virtual function = virtual function with = 0; forces derived classes to implement it
// best practice         = use inheritance only for clear "is-a" relationships

#include <iostream>
#include <string>
#include <vector>

// base class: Item
class Item {
protected:
    std::string name;
    int weight;

public:
    Item(const std::string& itemName, int itemWeight)
        : name(itemName), weight(itemWeight) {}

    virtual ~Item() {}

    // virtual function allows derived classes to override behavior
    virtual void use() const {
        std::cout << "Using " << name << "...\n";
    }

    virtual void display() const {
        std::cout << "Item: " << name << ", Weight: " << weight << "\n";
    }

    std::string getName() const { return name; }
    int getWeight() const { return weight; }
};

// derived class: Weapon
class Weapon : public Item {
private:
    int damage;

public:
    Weapon(const std::string& weaponName, int weaponWeight, int weaponDamage)
        : Item(weaponName, weaponWeight), damage(weaponDamage) {}

    void use() const override {
        std::cout << "Swinging the weapon " << name
                  << " with damage " << damage << "\n";
    }

    void display() const override {
        std::cout << "Weapon: " << name
                  << ", Weight: " << weight
                  << ", Damage: " << damage << "\n";
    }
};

// derived class: Ammo
class Ammo : public Item {
private:
    int rounds;

public:
    Ammo(const std::string& ammoName, int ammoWeight, int ammoRounds)
        : Item(ammoName, ammoWeight), rounds(ammoRounds) {}

    void use() const override {
        std::cout << "Reloading " << rounds << " rounds of " << name << "\n";
    }

    void display() const override {
        std::cout << "Ammo: " << name
                  << ", Weight: " << weight
                  << ", Rounds: " << rounds << "\n";
    }
};

// derived class: Aid
class Aid : public Item {
private:
    int healingPoints;

public:
    Aid(const std::string& aidName, int aidWeight, int aidHealingPoints)
        : Item(aidName, aidWeight), healingPoints(aidHealingPoints) {}

    void use() const override {
        std::cout << "Using " << name
                  << " to heal " << healingPoints << " health points\n";
    }

    void display() const override {
        std::cout << "Aid: " << name
                  << ", Weight: " << weight
                  << ", Healing Points: " << healingPoints << "\n";
    }
};

// derived class: Valuable
class Valuable : public Item {
private:
    int value;

public:
    Valuable(const std::string& valuableName, int valuableWeight, int valuableValue)
        : Item(valuableName, valuableWeight), value(valuableValue) {}

    void use() const override {
        std::cout << "Storing " << name
                  << " in the safe, value: " << value << "\n";
    }

    void display() const override {
        std::cout << "Valuable: " << name
                  << ", Weight: " << weight
                  << ", Value: " << value << "\n";
    }
};

int main() {
    std::cout << "Inheritance and Polymorphism Demo\n\n";

    std::vector<Item*> inventory;

    inventory.push_back(new Weapon("Axe", 5, 20));
    inventory.push_back(new Ammo("9mm Bullets", 2, 30));
    inventory.push_back(new Aid("Medkit", 3, 50));
    inventory.push_back(new Valuable("Gold Bar", 10, 100));

    for (const auto& item : inventory) {
        item->display(); // polymorphic call
        item->use();     // polymorphic call
        std::cout << "\n";
    }

    for (auto& item : inventory)
        delete item;

    return 0;
}
