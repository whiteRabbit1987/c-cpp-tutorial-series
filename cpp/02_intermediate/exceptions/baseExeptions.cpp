#include <iostream>
#include <exception>    
#include <string>  

// BaseException class              =   Defines a custom exception class derived from std::exception
//                                      It serves as the parent class for all other specialized exceptions.

// BaseException::BaseException     =   The constructor that takes an error message string.
//                                      It uses an initializer list to set the private member 'message_'.

// what() method                    =   virtual method inherited from std::exeption.
//                                      It must return a C-style string (const char*) describing the error.

// throw keyword                    =   Used to signal that an exceptional condition has occured,
//                                      stopping normal program flow and looking for a catch block.

// Class Definition (Self-Contained for learning)
class BaseException : public std::exception{
public:
    BaseException(const std::string& msg);
    const char* what() const noexcept override;

private:
    std::string message_;
};

// Implementation of the Constructor
BaseException::BaseException(const std::string& msg)
    : message_(msg)
{}

// Implementation of the what() method
const char* BaseException::what() const noexcept {
    return message_.c_str();
}

int main(){

    // Demonstration of exception throwing and catching
    try{
        throw BaseException("Database connection failed due to network timeout.");
    } catch(const BaseException& e){
        // This catch block handels our custom exception, using what() to print the message.
        std::cerr << "Caught Custom Exception: " << e.what() << '\n';
    } catch(const std::exception& e){
        // This is a generic handler for any standart C++ exception type.
        std::cerr << "Caught Standart Exception: " << e.what() << '\n';
    }

    return 0;
}