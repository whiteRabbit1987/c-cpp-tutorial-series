#include "include_guards.h"
#include <iostream>

// prints the explanation to the CLI
void IncludeGuardDemo::printExplanation() const {
    std::cout << "include guard fundamentals\n";
    std::cout << "purpose               = prevent multiple inclusion of the same header file\n";
    std::cout << "problem solved        = avoids redefinition errors when a header is included more than once\n";
    std::cout << "mechanism             = preprocessor checks if a unique macro is already defined\n";
    std::cout << "standard solution     = #ifndef / #define / #endif (portable, reliable, works everywhere)\n";
    std::cout << "pragma once           = simpler but non-standard; may fail on some compilers or file systems\n";
    std::cout << "best practice         = use include guards for portability; pragma once is optional convenience\n";
}
