#include <iostream>
#include <exception>
#include <string>

// FileReadError class         =   A specific exception class derived from BaseException.
//                                 It is used to signal problems encountered during file input operations,
//                                 such as the file not being found or permission issues.

// Inheritance                 =   The derived class inherits the 'what()' method from BaseException,
//                                 making it unnecessary to redefine the messaging logic.

// Constructor Chaining        =   The FileReadError constructor calls the BaseException constructor 
//                                 in its initializer list to store the error message.


// --- BaseException Definition (Required since no .h file exists) ---
class BaseException : public std::exception {
public:
    BaseException(const std::string& msg) : message_(msg) {} 
    const char* what() const noexcept override { return message_.c_str(); }
private:
    std::string message_; 
};

// --- FileReadError Definition and Implementation ---
class FileReadError : public BaseException {
public:
    // FileReadError constructor. It prepends context before passing the message up.
    FileReadError(const std::string& filename) 
        : BaseException("File Read Error: Could not open file '" + filename + "'") 
    {}
};


int main() {
    
    std::string file_to_read = "missing_data.txt";
    
    try {
        
        // Simulate a file reading failure
        if (file_to_read == "missing_data.txt") {
            // throw FileReadError("...") =   Signals a specific failure with file context.
            throw FileReadError(file_to_read);
        }

    } catch (const FileReadError& e) {
        
        // Specific Catch: Catches the most specific error type first.
        std::cerr << "File Operation Failed: " << e.what() << '\n';

    } catch (const BaseException& e) {
        
        // General Catch: Catches any other custom exceptions that derive from BaseException.
        std::cerr << "General Application Error: " << e.what() << '\n';
    }

    return 0;
}