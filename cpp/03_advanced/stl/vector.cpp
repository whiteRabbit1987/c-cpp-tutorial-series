#include <iostream>
#include <vector>

using namespace std;

// vector basics = dynamic array container from the C++ Standard Library
// common methods = .size()  .capacity()  .push_back()  .pop_back()
//                  .at()  .operator[]  .clear()  .empty()  .reserve()
// size()          = number of elements currently stored
// capacity()      = allocated storage (may be larger than size)
// push_back(x)    = add element to the end (may reallocate memory)
// pop_back()      = remove last element
// at(i)           = bounds-checked access (throws error if out of range)
// [i]             = fast access (NO bounds checking)
// reserve(n)      = pre-allocate memory WITHOUT changing size
// clear()         = remove all elements
// empty()         = returns true if size == 0

void print_info(const vector<int>& v) {
    cout << "content = ";
    for (int x : v) {
        cout << x << " ";
    }
    cout << endl;
    cout << "size     = " << v.size() << endl;
    cout << "capacity = " << v.capacity() << endl;
    cout << "is empty? " << (v.empty() ? "yes" : "no") << endl;
    cout << "---------" << endl;
}

int main(void) {

    // create empty vector
    vector<int> numbers;
    print_info(numbers);

    // reserve memory ahead of time (performance optimization)
    numbers.reserve(10);
    print_info(numbers);

    // add elements to the vector
    numbers.push_back(10);
    numbers.push_back(20);
    numbers.push_back(30);
    print_info(numbers);

    // access elements
    cout << "first element ([]) = " << numbers[0] << endl;
    cout << "second element (at) = " << numbers.at(1) << endl;
    cout << "---------" << endl;

    // remove last element
    numbers.pop_back();
    print_info(numbers);

    // clear all elements (capacity remains)
    numbers.clear();
    print_info(numbers);

    return 0;
}
