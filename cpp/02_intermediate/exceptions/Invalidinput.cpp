#include <iostream>
#include <exception>
#include <string>

// InvalidInput class          =   A specific exception class derived from BaseException.
//                                 It is designed to signal that user-provided data does not meet
//                                 the program's requirements (e.g., bad format, out of range).

// Constructor Context         =   The constructor allows passing the specific value or field name
//                                 that caused the error, making the resulting message highly informative.


// --- BaseException Definition (Required since no .h file exists) ---
class BaseException : public std::exception {
public:
    BaseException(const std::string& msg) : message_(msg) {} 
    const char* what() const noexcept override { return message_.c_str(); }
private:
    std::string message_; 
};

// --- InvalidInput Definition and Implementation ---
class InvalidInput : public BaseException {
public:
    // InvalidInput constructor takes the name of the problematic field and the requirement.
    InvalidInput(const std::string& field, const std::string& requirement) 
        : BaseException("Invalid Input: Field '" + field + "' failed. Requirement: " + requirement) 
    {}
};


int main() {
    
    int user_age = -5;
    
    try {
        
        // Simulate checking user input before processing
        if (user_age <= 0) {
            // throw InvalidInput(...) =   Signals a specific failure in user-supplied data.
            throw InvalidInput("Age", "Must be a positive number.");
        }
        
        std::cout << "User age accepted.\n"; // This line will not run if the exception is thrown

    } catch (const InvalidInput& e) {
        
        // Specific Catch: Catches errors directly related to bad user input validation.
        std::cerr << "Validation Failed: " << e.what() << '\n';

    } catch (const BaseException& e) {
        
        // General Catch: A safety net for any other custom application exceptions.
        std::cerr << "Unexpected Application Error: " << e.what() << '\n';
    }

    return 0;
}