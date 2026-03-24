// 03_advanced/language/enum_class_switch.cpp
// enum class             = strongly typed enumeration
// switch on enum class   = requires scoped values
// pair                   = simple struct-like container
// deque operations       = push_front, push_back, pop_front, pop_back
// command pattern        = list of operations applied sequentially
// purpose                = demonstrate enum class + switch + container manipulation

#include <iostream>
#include <deque>
#include <vector>
#include <string>
#include <utility>

enum class Operation {
    ADD_FRONT,
    ADD_BACK,
    REMOVE_FRONT,
    REMOVE_BACK
};

int main() {
    std::deque<std::pair<std::string, int>> schedule = {
        {"Sleep", 60},
        {"Play", 45},
        {"Eat", 20}
    };

    std::vector<std::pair<Operation, std::pair<std::string, int>>> ops = {
        {Operation::REMOVE_FRONT, {"", 0}},
        {Operation::ADD_FRONT, {"Groom", 15}},
        {Operation::ADD_BACK, {"Train", 30}}
    };

    for (const auto& op : ops) {
        switch (op.first) {
            case Operation::ADD_FRONT:
                schedule.push_front(op.second);
                break;
            case Operation::ADD_BACK:
                schedule.push_back(op.second);
                break;
            case Operation::REMOVE_FRONT:
                if (!schedule.empty()) schedule.pop_front();
                break;
            case Operation::REMOVE_BACK:
                if (!schedule.empty()) schedule.pop_back();
                break;
        }
    }

    for (const auto& s : schedule)
        std::cout << s.first << " (" << s.second << ")\n";

    return 0;
}
