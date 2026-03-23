// vector + iterator fundamentals demo
// begin() / end()     = return iterators (pointer‑like objects) to first / one‑past‑last
// std::find           = linear search; returns iterator to found element or end()
// iterator != end()   = check if search succeeded (end() means "not found")
// erase(it)           = removes the element at iterator position
// (*items)[index]     = access element through pointer to vector
// items->size()       = pointer syntax; items is a pointer to std::vector<std::string>

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

class Inventory{
public:
    // Add item to inventory
    void addItem(const std::string& item){
        if (items->size() < capacity)
            items->push_back(item);
        else
            std::cout << "Inventory is full, cannot add " << item << "\n";
    }

    // Remove item from inventory
    void removeItem(const std::string& item){
        // std::find returns an iterator pointing to the found element
        // or items->end() if the element is not found
        auto it = std::find(items->begin(), items->end(), item);

        if (it != items->end())
            items->erase(it); 
            // erase removes the element at the iterator position
        else
            std::cout << "Item " << item << " not found in inventory\n";
    }

    // Access item by index
    std::string getItem(int index) const{
        if (index >= 0 && index < items->size())
            return (*items)[index]; // dereference pointer, then index vector
        else
            return "Index out of bounds";
    }

    // Get number of items in the inventory
    int getItemCount() const{
        return items->size();
    }

    // Display inventory contents
    void displayInventory() const{
        std::cout << "Inventory: [ ";
        for (size_t i = 0; i < items->size(); ++i){
            std::cout << (*items)[i];
            if (i < items->size() - 1) std::cout << ", ";
        }
        std::cout << " ]\n";
    }

private:
    std::vector<std::string>* items; // pointer to vector (pointer syntax required)
    int capacity;                    // maximum number of items allowed
};

int main(){
    std::cout << "\n\n";
    return 0;
}
