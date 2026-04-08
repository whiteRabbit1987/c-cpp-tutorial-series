#include <iostream>
#include <queue>

typedef std::queue<std::string> list_t;

class MerchOrderSystem{
private:
    list_t orders;
    list_t priority_orders;
    
public:
    void place_order(std::string order, bool is_priority);
    int fulfill_order();
};
