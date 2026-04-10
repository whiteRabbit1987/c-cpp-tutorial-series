// linkedlist_manual.cpp
// purpose               = demonstrate a manually-linked singly linked list
// behavior              = each new node appends itself to the tail
// key idea              = raw pointer linking (no STL containers)
// best practice         = static head/tail for simple demo lists

#include <iostream>
using std::string;

class LinkedList {
private:
    static LinkedList* _tail;   // last node in the chain
public:
    static LinkedList* head;    // first node in the chain

private:
    string _value;
    LinkedList* _next;

public:
    // constructor: creates a node and links it to the tail
    LinkedList(string value)
        : _value(value), _next(nullptr)
    {
        // first node becomes head
        if (head == nullptr)
            head = this;

        // link previous tail to this node
        if (_tail != nullptr)
            _tail->_next = this;

        // update tail
        _tail = this;
    }

    LinkedList* next() { return _next; }
    string value() { return _value; }
};

// static member definitions
LinkedList* LinkedList::_tail = nullptr;
LinkedList* LinkedList::head = nullptr;

int main() {

    LinkedList a("A");
    LinkedList b("B");
    LinkedList c("C");

    LinkedList* current = LinkedList::head;

    while (current != nullptr) {
        std::cout << current->value() << "\n";
        current = current->next();
    }

    return 0;
}
