// include guard fundamentals
// purpose               = prevent multiple inclusion of the same header file
// problem solved        = avoids redefinition errors when a header is included more than once
// mechanism             = preprocessor checks if a unique macro is already defined
// standard solution     = #ifndef / #define / #endif (portable, reliable, works everywhere)
// pragma once           = simpler but non-standard; may fail on some compilers or file systems
// best practice         = use include guards for portability; pragma once is optional convenience

#pragma once

#ifndef INVENTORY_H
#define INVENTORY_H

#include <vector>
#include <string>
#include <algorithm>
#include <iostream>

class Inventory{
public:
    // Constructor
    Inventory();

    // Overloaded Constructor
    Inventory(int capacity_i);

    // Destructor
    ~Inventory();

    // Add item to inventory
    void addItem(const std::string& item);

    // Remove item from inventory
    void removeItem(const std::string& item);

    // Access item by index
    std::string getItem(int index) const;

    // Get number of items in the inventory
    int getItemCount() const;

    // Display inventory contents
    void displayInventory() const;

private:
    std::vector<std::string> *items; // Pointer to a vector of items
    int capacity; // Maximum number of items allowed
};

#endif // INVENTORY_H
