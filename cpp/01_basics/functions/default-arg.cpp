// default arguments demo
// default params     = values used when caller omits arguments (set in declaration)
// right‑to‑left rule = once a param has a default, all to its right must also have defaults
// overload reduction = default args reduce need for multiple overloads
// const std::string& = avoids copying string argument (binds to lvalue or temporary)

#include <iostream>
#include <string>

void createZombie(const std::string& name = "Zombie", int health = 100){
    std::cout << name << " has " << health << " health points.\n";
}

int main(){
    createZombie();                 // uses both defaults
    createZombie("Crawler");        // uses default health
    createZombie("Runner", 150);    // overrides both defaults
    return 0;
}
