// types_intro.cpp
// advanced C++ type system overview
// purpose               = introduce core type-system mechanics used in modern C++
// topics                = auto, decltype, decltype(auto), type traits, references,
//                         value categories, forwarding references, std::move/forward
// best practice         = understand how C++ deduces, preserves, and transforms types

#include <iostream>
#include <type_traits>
#include <utility>

int main() {

    // ------------------------------------------------------------
    // auto
    // ------------------------------------------------------------
    // deduces type from initializer
    // drops const and reference qualifiers
    int x = 10;
    const int cx = x;
    int& rx = x;

    auto a = x;     // int
    auto b = cx;    // int (const dropped)
    auto c = rx;    // int (reference dropped)


    // ------------------------------------------------------------
    // decltype(expr)
    // ------------------------------------------------------------
    // inspects the type of an expression without evaluating it
    // preserves const, &, && qualifiers

    decltype(x) d = 1;      // int
    decltype(cx) e = 2;     // const int
    decltype(rx) f = x;     // int&

    // parentheses change the rule:
    decltype((x)) g = x;    // int& (lvalue expression → reference)
    decltype((cx)) h = x;   // const int&


    // ------------------------------------------------------------
    // decltype(auto)
    // ------------------------------------------------------------
    // deduces type exactly, including references
    decltype(auto) i = (x); // int&


    // ------------------------------------------------------------
    // value categories
    // ------------------------------------------------------------
    // lvalue   = has identity, addressable
    // xvalue   = expiring value (e.g., std::move(x))
    // prvalue  = temporary value (e.g., x + 1)

    int y = 5;
    int&& r1 = std::move(y); // xvalue → binds to rvalue reference
    int&& r2 = 10;           // prvalue → binds to rvalue reference


    // ------------------------------------------------------------
    // reference collapsing rules
    // ------------------------------------------------------------
    // T&  &  → T&
    // T&  && → T&
    // T&& &  → T&
    // T&& && → T&&

    // used heavily in templates and forwarding references


    // ------------------------------------------------------------
    // forwarding references (formerly "universal references")
    // ------------------------------------------------------------
    // template <typename T>
    // void func(T&& param);
    //
    // param becomes:
    //  - T&  if argument is lvalue
    //  - T&& if argument is rvalue

    auto forward_demo = [](auto&& param) {
        using T = decltype(param);
        // param preserves the caller's value category
    };


    // ------------------------------------------------------------
    // std::move and std::forward
    // ------------------------------------------------------------
    // std::move(x)     = cast x to xvalue (does NOT move by itself)
    // std::forward<T>  = preserve original value category in templates

    int z = 42;
    int&& moved = std::move(z); // z is now treated as an xvalue


    // ------------------------------------------------------------
    // type traits (std::type_traits)
    // ------------------------------------------------------------
    // compile-time utilities for inspecting/modifying types

    static_assert(std::is_integral<int>::value, "int should be integral");
    static_assert(std::is_same<decltype(x), int>::value, "x is int");
    static_assert(std::is_lvalue_reference<decltype((x))>::value,
                  "(x) is an lvalue reference");


    // ------------------------------------------------------------
    // template type deduction vs decltype deduction
    // ------------------------------------------------------------
    // auto / template deduction:
    //   - drops references and const
    //
    // decltype:
    //   - preserves everything exactly

    auto auto_deduce = rx;          // int
    decltype(rx) decltype_deduce = x; // int&


    std::cout << "types intro loaded\n";
    return 0;
}
