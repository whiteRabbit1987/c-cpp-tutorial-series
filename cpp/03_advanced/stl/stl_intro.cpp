// 03_advanced/stl/stl_intro.cpp
// stl overview
// purpose               = introduce core stl containers and adapters
// sequence containers   = vector, deque, list
// associative           = set, map
// unordered             = hash-based versions of associative containers
// adapters              = stack, queue, priority_queue
// pair                  = simple 2-value utility type
// best practice         = choose container based on access pattern and complexity needs

#include <iostream>
#include <vector>
#include <deque>
#include <list>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <stack>
#include <queue>
#include <utility>

int main() {

    // --- sequence containers ---

    // vector: dynamic array with fast random access
    std::vector<int> scores = {10, 20, 30};
    scores.push_back(40);

    // deque: fast insertion/removal at both ends
    std::deque<std::string> actions = {"Pass", "Shoot", "Defend"};
    actions.push_front("Dribble");
    actions.push_back("Score");

    // list: doubly linked list, fast insertion anywhere
    std::list<std::string> checkpoints = {"Entrance", "Lobby", "Storage"};
    checkpoints.push_back("Roof");


    // --- associative containers ---

    // set: sorted, unique elements
    std::set<std::string> items = {"Coin", "Gem", "Star"};
    items.insert("Key");

    // pair: simple 2-value struct (first, second)
    std::pair<std::string, int> playerStat("Alice", 75);

    // map: sorted key-value pairs
    std::map<std::string, int> stats;
    stats["Goals"] = 10;
    stats["Assists"] = 5;
    stats["Saves"] = 3;


    // --- unordered containers (hash-based) ---

    std::unordered_map<std::string, int> fastLookup;
    fastLookup["HP"] = 100;
    fastLookup["MP"] = 50;

    std::unordered_set<std::string> visitedRooms = {"Hall", "Kitchen", "Basement"};


    // --- container adapters ---

    // stack: LIFO
    std::stack<std::string> gameStates;
    gameStates.push("Main Menu");
    gameStates.push("Level 1");
    gameStates.push("Level 2");

    // queue: FIFO
    std::queue<std::string> eventQueue;
    eventQueue.push("Start");
    eventQueue.push("Goal");
    eventQueue.push("Half-Time");

    // priority_queue: highest priority first
    std::priority_queue<int> aiTasks;
    aiTasks.push(1);
    aiTasks.push(3);
    aiTasks.push(2);


    // --- output examples ---

    std::cout << "Vector last score: " << scores.back() << "\n";
    std::cout << "Deque front action: " << actions.front() << "\n";
    std::cout << "List last checkpoint: " << checkpoints.back() << "\n";

    std::cout << "Set contains Key: " << (items.count("Key") ? "yes" : "no") << "\n";
    std::cout << "Pair: " << playerStat.first << " " << playerStat.second << "\n";

    std::cout << "Map Goals: " << stats["Goals"] << "\n";
    std::cout << "Unordered HP: " << fastLookup["HP"] << "\n";

    std::cout << "Stack top: " << gameStates.top() << "\n";
    std::cout << "Queue front: " << eventQueue.front() << "\n";
    std::cout << "Priority top: " << aiTasks.top() << "\n";

    return 0;
}
// 03_advanced/stl/stl_intro.cpp
// stl overview
// purpose               = introduce core stl containers and adapters
// sequence containers   = vector, deque, list
// associative           = set, map
// unordered             = hash-based versions of associative containers
// adapters              = stack, queue, priority_queue
// pair                  = simple 2-value utility type
// best practice         = choose container based on access pattern and complexity needs

#include <iostream>
#include <vector>
#include <deque>
#include <list>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <stack>
#include <queue>
#include <utility>

int main() {

    // --- sequence containers ---

    // vector: dynamic array with fast random access
    std::vector<int> scores = {10, 20, 30};
    scores.push_back(40);

    // deque: fast insertion/removal at both ends
    std::deque<std::string> actions = {"Pass", "Shoot", "Defend"};
    actions.push_front("Dribble");
    actions.push_back("Score");

    // list: doubly linked list, fast insertion anywhere
    std::list<std::string> checkpoints = {"Entrance", "Lobby", "Storage"};
    checkpoints.push_back("Roof");


    // --- associative containers ---

    // set: sorted, unique elements
    std::set<std::string> items = {"Coin", "Gem", "Star"};
    items.insert("Key");

    // pair: simple 2-value struct (first, second)
    std::pair<std::string, int> playerStat("Alice", 75);

    // map: sorted key-value pairs
    std::map<std::string, int> stats;
    stats["Goals"] = 10;
    stats["Assists"] = 5;
    stats["Saves"] = 3;


    // --- unordered containers (hash-based) ---

    std::unordered_map<std::string, int> fastLookup;
    fastLookup["HP"] = 100;
    fastLookup["MP"] = 50;

    std::unordered_set<std::string> visitedRooms = {"Hall", "Kitchen", "Basement"};


    // --- container adapters ---

    // stack: LIFO
    std::stack<std::string> gameStates;
    gameStates.push("Main Menu");
    gameStates.push("Level 1");
    gameStates.push("Level 2");

    // queue: FIFO
    std::queue<std::string> eventQueue;
    eventQueue.push("Start");
    eventQueue.push("Goal");
    eventQueue.push("Half-Time");

    // priority_queue: highest priority first
    std::priority_queue<int> aiTasks;
    aiTasks.push(1);
    aiTasks.push(3);
    aiTasks.push(2);


    // --- output examples ---

    std::cout << "Vector last score: " << scores.back() << "\n";
    std::cout << "Deque front action: " << actions.front() << "\n";
    std::cout << "List last checkpoint: " << checkpoints.back() << "\n";

    std::cout << "Set contains Key: " << (items.count("Key") ? "yes" : "no") << "\n";
    std::cout << "Pair: " << playerStat.first << " " << playerStat.second << "\n";

    std::cout << "Map Goals: " << stats["Goals"] << "\n";
    std::cout << "Unordered HP: " << fastLookup["HP"] << "\n";

    std::cout << "Stack top: " << gameStates.top() << "\n";
    std::cout << "Queue front: " << eventQueue.front() << "\n";
    std::cout << "Priority top: " << aiTasks.top() << "\n";

    return 0;
}
