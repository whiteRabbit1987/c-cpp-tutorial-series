#include <iostream>
#include <exception>
#include <string>

// NetworkError class          =   A specialized exception class derived from BaseException.
//                                 It is used to signal issues related to external communication,
//                                 ensuring network-related problems are clearly identifiable.

// Constructor Context         =   The constructor takes the host/service and the specific type of error
//                                 (e.g., 'Timeout' or 'DNS failure') to provide maximum diagnostic detail.


// --- BaseException Definition (Required since no .h file exists) ---
class BaseException : public std::exception {
public:
    BaseException(const std::string& msg) : message_(msg) {} 
    const char* what() const noexcept override { return message_.c_str(); }
private:
    std::string message_; 
};

// --- NetworkError Definition and Implementation ---
class NetworkError : public BaseException {
public:
    // NetworkError constructor takes the service being accessed and the specific failure type.
    NetworkError(const std::string& service, const std::string& error_type) 
        : BaseException("Network Error accessing '" + service + "'. Failure Type: " + error_type) 
    {}
};


int main() {
    
    std::string service_url = "api.external.com";
    
    try {
        
        // Simulate a network failure
        std::string network_status = "Connection Reset";
        
        if (network_status == "Connection Reset") {
            // throw NetworkError(...) =   Signals a specific external communication error.
            throw NetworkError(service_url, network_status);
        }
        
    } catch (const NetworkError& e) {
        
        // Specific Catch: Handles network-related errors, allowing for recovery strategies 
        //                 (like automatic retries) to be implemented here.
        std::cerr << "Network Communication Failed: " << e.what() << '\n';

    } catch (const BaseException& e) {
        
        // General Catch: Catches any other custom exceptions that were not caught specifically.
        std::cerr << "General Application Error: " << e.what() << '\n';
    }

    return 0;
}