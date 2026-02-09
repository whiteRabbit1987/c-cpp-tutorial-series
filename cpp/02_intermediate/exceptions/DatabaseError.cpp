#include <iostream>
#include <exception>
#include <string>

// DatabaseError class         =   A specialized exception class derived from BaseException.
//                                 It inherits all methods (like what()) and members from the base class.

// Inheritance                 =   Allows specific error types to be grouped under a general type (BaseException).
//                                 This lets a catch block handle both specific errors (DatabaseError)
//                                 and general errors (BaseException).

// Constructor Chaining        =   The derived class constructor (DatabaseError) calls the base class constructor
//                                 (BaseException) in its initializer list to handle the error message storage.


// --- BaseException Definition (Required since no .h file exists) ---
class BaseException : public std::exception {
public:
    BaseException(const std::string& msg) : message_(msg) {} 
    const char* what() const noexcept override { return message_.c_str(); }
private:
    std::string message_; 
};

// --- DatabaseError Definition and Implementation ---
class DatabaseError : public BaseException {
public:
    // DatabaseError constructor takes the message string
    // It passes this message directly to the BaseException constructor.
    DatabaseError(const std::string& msg) 
        : BaseException("Database Error: " + msg) 
    {}
};


int main() {
    
    // Demonstration of catching a derived exception
    try {
        
        // Throw a specific DatabaseError
        throw DatabaseError("Failed to connect to MySQL server.");

    } catch (const DatabaseError& e) {
        
        // Specific Catch: This block executes only if a DatabaseError is thrown.
        std::cerr << "Specific Database Handler: " << e.what() << '\n';

    } catch (const BaseException& e) {
        
        // General Catch: This block would catch other specific errors (like FileReadError), 
        //                 but not the one specifically caught above.
        std::cerr << "General Base Handler: " << e.what() << '\n';
    }

    return 0;
}