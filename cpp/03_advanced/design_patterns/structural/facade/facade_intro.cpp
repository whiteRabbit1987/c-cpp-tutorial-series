#include <iostream>

// facade pattern          =   provide a simplified interface to a complex subsystem
// subsystem               =   multiple classes with complicated interactions
// facade                  =   wrapper that exposes only what the client needs
// goal                    =   hide complexity and reduce coupling

class CPU {
public:
    void freeze() { std::cout << "CPU freeze\n"; }
    void jump(long addr) { std::cout << "CPU jump to " << addr << "\n"; }
    void execute() { std::cout << "CPU execute\n"; }
};

class Memory {
public:
    void load(long addr, const std::string& data) {
        std::cout << "Memory load '" << data << "' at " << addr << "\n";
    }
};

class HardDrive {
public:
    std::string read(long lba, int size) {
        return "OS_BOOT_DATA";
    }
};

// Facade
class ComputerFacade {
private:
    CPU cpu;
    Memory mem;
    HardDrive hd;
public:
    void start() {
        cpu.freeze();
        mem.load(0, hd.read(0, 1024));
        cpu.jump(0);
        cpu.execute();
    }
};

int main() {
    ComputerFacade computer;
    computer.start();
    return 0;
}
