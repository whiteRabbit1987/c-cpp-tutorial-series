#include <iostream>
#include <queue>

// queue_basics.cpp
// purpose               = demonstrate FIFO behavior using std::queue
// container             = std::queue<int> for first-in-first-out ordering
// operations            = push(), pop(), front(), empty(), size()
// notes                 = queue does not allow iteration or random access

int main() {

    std::queue<int> q;

    // push elements (enqueue)
    q.push(10);
    q.push(20);
    q.push(30);

    std::cout << "size = " << q.size() << "\n";
    std::cout << "front = " << q.front() << "\n";

    // pop elements (dequeue)
    q.pop();   // removes 10
    std::cout << "front after pop = " << q.front() << "\n";

    q.pop();   // removes 20
    std::cout << "front after pop = " << q.front() << "\n";

    q.pop();   // removes 30

    if (q.empty())
        std::cout << "queue is now empty\n";

    return 0;
}
