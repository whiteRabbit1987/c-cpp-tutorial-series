// 03_advanced/stl/advanced_containers.cpp
// advanced stl containers
// queue                  = fifo container adapter
// stack                  = lifo container adapter
// deque                  = double-ended queue
// pair                   = lightweight 2-value struct
// nested templates       = containers inside containers
// purpose                = demonstrate container adapters and composition

#include <iostream>
#include <queue>
#include <stack>
#include <deque>
#include <string>
#include <utility>

int main() {
    std::queue<std::string> eventQueue;
    std::stack<std::string> undoStack;
    std::deque<std::pair<std::string, int>> schedule;

    eventQueue.push("Move");
    eventQueue.push("Attack");
    eventQueue.push("Loot");

    while (!eventQueue.empty()) {
        std::string e = eventQueue.front();
        eventQueue.pop();
        undoStack.push(e);
    }

    schedule.push_back({"Eat", 15});
    schedule.push_front({"Sleep", 60});
    schedule.push_back({"Play", 30});

    for (const auto& s : schedule)
        std::cout << s.first << " (" << s.second << ")\n";

    return 0;
}
