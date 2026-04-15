// lambda_anatomy.cpp
// purpose               = identify each part of a lambda expression
// topics                = capture list, parameters, return type, body, variable

#include <iostream>

int main() {

    auto add = [](int a, int b) -> int { return a + b; };
    // ^^^^  variable holding the lambda (compiler deduces type)
    //      ^---------------------------^
    //      lambda expression
    //
    // []          = capture list (captures no external variables)
    // (int a, int b) = parameter list
    // -> int      = explicit return type
    // { return a + b; } = lambda body

    int result = add(4, 5);
    std::cout << result << std::endl;

    return 0;
}
