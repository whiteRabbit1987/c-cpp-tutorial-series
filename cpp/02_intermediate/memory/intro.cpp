// pointer fundamentals demo
// stack vs heap        = stack variables die with scope; heap persists until delete
// new / delete         = manual heap allocation + manual cleanup (risk: leaks, dangling ptrs)
// -> operator          = member access through a pointer (syntactic sugar for (*ptr).member)
// static_cast<T*>      = explicit cast required for void* before dereferencing
// unique_ptr           = RAII smart pointer that auto-deletes (prevents leaks)

#include <iostream>
#include <memory>

struct Character {
    int health;
    int strength;
};

int main() {
    // heap allocation via new = dynamic lifetime (not tied to scope)
    Character* hero = new Character{100, 50};

    std::cout << hero->health << '\n';   // -> = pointer member access
    std::cout << hero->strength << '\n';

    delete hero; // manual cleanup required (raw pointer)

    // void* can point to anything but must be cast before dereference
    float playerHealth = 100.0f;
    void* generic = &playerHealth; 
    float actual = *(static_cast<float*>(generic)); // static_cast needed: void* has no type info

    // smart pointer example (auto cleanup via RAII)
    std::unique_ptr<Character> boss = std::make_unique<Character>(); 
    boss->health = 200;
    boss->strength = 40;

    std::cout << boss->health << '\n';
    std::cout << boss->strength << '\n';

    return 0;
}
