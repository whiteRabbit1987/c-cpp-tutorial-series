// include guard fundamentals
// purpose               = prevent multiple inclusion of the same header file
// problem solved        = avoids redefinition errors when a header is included more than once
// mechanism             = preprocessor checks if a unique macro is already defined
// standard solution     = #ifndef / #define / #endif (portable, reliable, works everywhere)
// pragma once           = simpler but non-standard; may fail on some compilers or file systems
// best practice         = use include guards for portability; pragma once is optional convenience

#ifndef INCLUDE_GUARDS_H
#define INCLUDE_GUARDS_H

class IncludeGuardDemo {
public:
    void printExplanation() const; // const because it does not modify the object
};

#endif // INCLUDE_GUARDS_H
