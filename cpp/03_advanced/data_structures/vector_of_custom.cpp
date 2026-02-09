#include <iostream>
#include <vector>
#include <string>

// ItemData struct              =   The custom structure defined earlier.
//                                  It serves as the element type (T) for the std::vector<T>.

// std::vector<ItemData>        =   A dynamic array where each slot holds a complete ItemData object.
//                                  This container is ideal for managing collections like inventories or player lists.

// push_back() with struct      =   Creates a new ItemData object at the end of the vector. The object is
//                                  initialized using initializer list syntax {}.

struct ItemData{
    int itemID;
    float price;
    std::string name;
};

int main(){

    // Create a vector where the elements are ItemData structs
    std::vector<ItemData> shoppingCart;

    // 1. Adding an element using push_back and initializer list
    shoppingCart.push_back({
        101, 
        19.99f, 
        "Health Potion"
    });

    // 2. Adding another element using a pre-defined struct variable
    ItemData boots = {
        503, 
        75.00f, 
        "Boots of Speed"
    };
    shoppingCart.push_back(boots);
    
    // Demonstration of accessing struct members within the vector
    // shoppingCart[1].name       =   Accesses the second element, then its 'name' member.
    std::cout << "--- Shopping Cart (Size: " << shoppingCart.size() << ") ---" << '\n';
    std::cout << "Item 1: " << shoppingCart[0].name << " | Price: $" << shoppingCart[0].price << '\n';
    std::cout << "Item 2: " << shoppingCart[1].name << " | Price: $" << shoppingCart[1].price << '\n';

    return 0;
}