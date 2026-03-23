// operator overloading fundamentals
// purpose               = allow intuitive syntax for custom types
// operator+=            = add or append to the object
// operator-=            = remove or subtract from the object
// operator[]            = index access; should be const if it does not modify state
// operator<<            = stream output; must be a free function (not a member)
// return *this          = enables chaining (obj += x += y)
// best practice         = keep operator behavior intuitive and consistent with built-in types

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

class Inventory {
public:
    // constructor initializes vector and capacity
    Inventory(int cap = 10)
        : capacity(cap)
    {
        items = new std::vector<std::string>();
    }

    // destructor frees allocated vector
    ~Inventory() {
        delete items;
    }

    // operator+= adds an item (like push_back)
    Inventory& operator+=(const std::string& item) {
        if (items->size() < capacity)
            items->push_back(item);
        else
            std::cout << "Inventory full, cannot add: " << item << "\n";
        return *this; // enables chaining
    }

    // operator-= removes an item if found
    Inventory& operator-=(const std::string& item) {
        auto it = std::find(items->begin(), items->end(), item);
        if (it != items->end())
            items->erase(it);
        else
            std::cout << "Item not found: " << item << "\n";
        return *this; // enables chaining
    }

    // operator[] provides read-only access by index
    std::string operator[](int index) const {
        if (index >= 0 && index < static_cast<int>(items->size()))
            return (*items)[index];
        return "Index out of bounds";
    }

    // getter for item count
    int getItemCount() const {
        return items->size();
    }

    // display function (const because it does not modify the object)
    void display() const {
        std::cout << "Inventory: [ ";
        for (size_t i = 0; i < items->size(); ++i) {
            std::cout << (*items)[i];
            if (i < items->size() - 1) std::cout << ", ";
        }
        std::cout << " ]\n";
    }

    // friend operator<< for printing with std::cout
    friend std::ostream& operator<<(std::ostream& os, const Inventory& inv) {
        os << "Inventory: [ ";
        for (size_t i = 0; i < inv.items->size(); ++i) {
            os << (*inv.items)[i];
            if (i < inv.items->size() - 1) os << ", ";
        }
        os << " ]";
        return os;
    }

private:
    std::vector<std::string>* items;
    int capacity;
};

int main() {
    Inventory inv(5);

    inv += "Sword";
    inv += "Shield";
    inv += "Potion";

    inv.display();

    inv -= "Shield";
    inv.display();

    std::cout << "Item at index 0: " << inv[0] << "\n";

    std::cout << inv << "\n";

    return 0;
}
