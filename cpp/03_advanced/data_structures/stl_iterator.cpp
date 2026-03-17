// vector iterator demo
// auto iterator        = deduces std::vector<int>::iterator (pointer‑like object)
// next(it, n)          = moves iterator forward by n (uses iterator arithmetic)
// *numPtr              = dereference iterator to access the int it points to
// end()                = one‑past‑last element; never dereference it
// iterator != end()    = standard loop condition for iterator traversal

#include <iostream>
#include <vector>

int main(){
    std::vector<int> numbers = {1, 3, 5, 7, 9};

    auto numPtr = numbers.begin(); // iterator to first element

    while(numPtr != numbers.end()){
        numPtr = next(numPtr, 1);  // next(it,1) → move iterator forward by 1
        if(numPtr == numbers.end()) 
            break;                 // end() is not a valid element to dereference

        std::cout << *numPtr << " \n"; // *numPtr dereferences iterator → gives int
        std::cout << "Executing .....\n";
    }

    std::cout << "Finished!";
    return 0;
}
