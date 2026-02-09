#include <iostream>
#include <string>

// Custom Struct Array    =   Allows the creation of arrays where each element is an instance of a 
//                           user-defined data structure (struct or class).
//                           The compiler treats custom types identically to built-in types like int.

// Initialization         =   Can be done using the subscript operator (arrayName[index]) followed by 
//                           the member access operator (.).

struct ItemData{
    int itemID;
    float price;
    std::string name;
};

int main(){

    ItemData inventoryArray[3];

    inventoryArray[0].itemID = 101;
    inventoryArray[0].price = 19.99f;
    inventoryArray[0].name = "Health Potion";

    inventoryArray[1].itemID = 205;
    inventoryArray[1].price = 5.00f;
    inventoryArray[1].name = "Iron Ore";

    inventoryArray[2].itemID = 402;
    inventoryArray[2].price = 1.25f;
    inventoryArray[2].name = "Bread";


    std::cout << "--- Inventory Contents ---\n";
    std::cout << "Item: " << inventoryArray[0].name << " | Price: $" << inventoryArray[0].price << '\n';
    std::cout << "Item: " << inventoryArray[1].name << " | Price: $" << inventoryArray[1].price << '\n';
    std::cout << "Item: " << inventoryArray[2].name << " | Price: $" << inventoryArray[2].price << '\n';

    return 0;
}