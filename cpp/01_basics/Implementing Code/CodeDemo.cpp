#include "inventory.h"
#include <iostream>

int main(){
    // Create an inventory with capacity of 5 items
    Inventory myInventory(5); 
    
    // Add 5 items
    myInventory.addItem("Health Potion"); 
    myInventory.addItem("Mana Potion");
    myInventory.addItem("Sword");
    myInventory.addItem("Shield");
    myInventory.addItem("Bow");

    // Display current inventory
    myInventory.displayInventory(); 

    // Try to add another item when inventory is full
    myInventory.addItem("Arrow");

    // Remove an item
    myInventory.removeItem("Mana Potion"); 

    // Display the item count
    std::cout << "The inventory now contains: " << myInventory.getItemCount() << " items." << std::endl;

    // Access item by index
    std::cout << "Item at index 2: " << myInventory.getItem(2) << std::endl; 

    // Display final state of inventory
    myInventory.displayInventory();

    std::cout << std::endl << std::endl;
    return 0;
}
