#include "cat_orders.h"

void MerchOrderSystem::place_order(std::string order, bool is_priority){
    if(is_priority){
        priority_orders.push(order);
        std::cout << "Order '" << order << "' places as priority.\n"; 
    } else {
        orders.push(order);
        std::cout << "Order '" << order << "' placed.\n";
    }
};

int MerchOrderSystem::fulfill_order(){
    if(!priority_orders.empty()){
            std::cout << "\nProcessing order " << priority_orders.front();
            priority_orders.pop();
    } else {
        if(orders.empty()){
            std::cout << "\nThere are currently no orders to process!";
            return -1;
        } else {
            std::cout << "\nProcessing order " << orders.front();
            orders.pop();
        }
    }
    return 0;
};

int main() {
    MerchOrderSystem MyOrders;
    MyOrders.place_order("Laptop", 0);
    MyOrders.place_order("Cat Food", 1);
    MyOrders.place_order("PC", 0);
    MyOrders.place_order("Human Food", 0);
    MyOrders.place_order("Cat toys", 1);
    MyOrders.place_order("Laptop", 0);

    int current;
    while(current != -1){
        current = MyOrders.fulfill_order();
    };
    
    return 0;
}