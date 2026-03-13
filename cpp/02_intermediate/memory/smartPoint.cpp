// smart pointer fundamentals
// unique_ptr        = exclusive ownership; auto-deletes when going out of scope (RAII)
// shared_ptr        = shared ownership; reference-counted; last owner frees memory
// make_unique       = safe heap allocation without raw new (prevents leaks)
// make_shared       = allocates control block + object together (more efficient than raw new)
// use_count()       = returns how many shared_ptr instances own the same object

#include <iostream>
#include <memory>

struct Enemy {
    int health;
    int attackPower;
};

int main() {
    // unique_ptr: sole owner of the object
    std::unique_ptr<Enemy> boss = std::make_unique<Enemy>(); 
    boss->health = 200;
    boss->attackPower = 40;

    std::cout << boss->health << '\n';
    std::cout << boss->attackPower << '\n';

    // shared_ptr: multiple owners share the same object
    std::shared_ptr<Enemy> goblin = std::make_shared<Enemy>(); 
    goblin->health = 50;
    goblin->attackPower = 10;

    std::shared_ptr<Enemy> goblinAlly = goblin; 
    // assignment copies the shared_ptr, not the object → increments ref count

    std::cout << goblin->health << '\n';
    std::cout << goblin->attackPower << '\n';
    std::cout << goblin.use_count() << '\n'; // shows how many shared_ptr own this object

    return 0; // unique_ptr and shared_ptr auto-cleanup here (no delete needed)
}
