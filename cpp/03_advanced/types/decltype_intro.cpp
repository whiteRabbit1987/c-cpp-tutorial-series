// decltype_intro.cpp
// purpose               = demonstrate decltype type deduction rules
// decltype(expr)        = inspects the type of an expression without evaluating it
// key behavior          = preserves const, &, && qualifiers
// decltype(auto)        = deduces type exactly, including references

#include <iostream>
#include <typeinfo>

int main() {
    int x = 10;
    const int cx = x;
    int& rx = x;

    // basic decltype
    decltype(x) a = 1;          // int
    decltype(cx) b = 2;         // const int
    decltype(rx) c = x;         // int&   (reference preserved)

    // parentheses change the rule
    decltype((x)) d = x;        // int&   (lvalue expression → reference)
    decltype((cx)) e = x;       // const int&

    // expression types
    decltype(x + 1) f = 5;      // int (arithmetic produces rvalue int)

    // decltype(auto) preserves references
    decltype(auto) g = (x);     // int&

    std::cout << "decltype(x)      = int\n";
    std::cout << "decltype(cx)     = const int\n";
    std::cout << "decltype(rx)     = int&\n";
    std::cout << "decltype((x))    = int&\n";
    std::cout << "decltype((cx))   = const int&\n";
    std::cout << "decltype(x+1)    = int\n";
    std::cout << "decltype(auto) g = int&\n";

    return 0;
}
