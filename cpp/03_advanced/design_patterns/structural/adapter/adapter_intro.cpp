// adapter_intro.cpp
// Structural Pattern: Adapter
// Purpose: Convert one interface into another interface the client expects.
// When to use: When you have existing code with an incompatible interface.

#include <iostream>

// Existing class with incompatible interface
class LegacyPrinter {
public:
    void oldPrint(const std::string& msg) {
        std::cout << "[LegacyPrinter] " << msg << "\n";
    }
};

// Target interface the client expects
class IPrinter {
public:
    virtual void print(const std::string& msg) = 0;
    virtual ~IPrinter() = default;
};

// Adapter: makes LegacyPrinter match IPrinter
class PrinterAdapter : public IPrinter {
private:
    LegacyPrinter& legacy;
public:
    PrinterAdapter(LegacyPrinter& lp) : legacy(lp) {}

    void print(const std::string& msg) override {
        legacy.oldPrint(msg); // translate call
    }
};

int main() {
    LegacyPrinter legacy;
    PrinterAdapter adapter(legacy);

    adapter.print("Hello through the Adapter pattern");
    return 0;
}
