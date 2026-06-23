#include <iostream>
#include <queue>
#include <vector>

// priority_queue_basics.cpp
// purpose               = demonstrate max‑heap behavior using std::priority_queue
// container             = std::priority_queue<int> for highest‑value retrieval
// ordering              = largest element always at top (default comparator)
// operations            = push(), pop(), top(), empty(), size()
// notes                 = no iteration; underlying container is typically vector

int main() {

    std::priority_queue<int> pq;

    // push values (heap organizes automatically)
    pq.push(10);
    pq.push(50);
    pq.push(20);
    pq.push(40);

    std::cout << "size = " << pq.size() << "\n";
    std::cout << "top  = " << pq.top()  << "\n";   // should be 50

    // pop values in priority order
    while (!pq.empty()) {
        std::cout << "popping " << pq.top() << "\n";
        pq.pop();
    }

    return 0;
}
