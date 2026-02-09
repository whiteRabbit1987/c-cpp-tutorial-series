#include <iostream>
#include <exception>
#include <string>

// FileWriteError class        =   A specific exception class derived from BaseException.
//                                 It is used to signal problems during file output operations,
//                                 such as disk space issues, permission denied, or a failure to create the file.

// Constructor Chaining        =   The FileWriteError constructor takes a file name and a reason,
//                                 then passes a combined, descriptive message up to the BaseException constructor.


// --- BaseException Definition (Required since no .h file exists) ---
class BaseException : public std::exception {
public:
    BaseException(const std::string& msg) : message_(msg) {} 
    const char* what() const noexcept override { return message_.c_str(); }
private:
    std::string message_; 
};

// --- FileWriteError Definition and Implementation ---
class FileWriteError : public BaseException {
public:
    // FileWriteError constructor takes the filename and an extra error reason.
    FileWriteError(const std::string& filename, const std::string& reason) 
        : BaseException("File Write Error: Failed to write to '" + filename + "'. Reason: " + reason) 
    {}
};


int main() {
    
    std::string file_to_write = "log.txt";
    
    try {
        
        // Simulate a file writing failure due to a specific reason
        std::string error_reason = "Disk is full";
        if (error_reason == "Disk is full") {
            // throw FileWriteError(...) =   Signals a specific output failure with context.
            throw FileWriteError(file_to_write, error_reason);
        }

    } catch (const FileWriteError& e) {
        
        // Specific Catch: Catches errors related specifically to file output.
        std::cerr << "File Output Failed: " << e.what() << '\n';

    } catch (const BaseException& e) {
        
        // General Catch: Catches any custom exceptions (like FileReadError, DatabaseError)
        //                 that were not caught specifically above.
        std::cerr << "General Application Error: " << e.what() << '\n';
    }

    return 0;
}