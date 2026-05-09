#include <iostream>
#include <string>
#include <memory>

// decorator pattern              =   dynamically add behavior to objects without modifying their code
//                                    avoids subclass explosion by using composition instead of inheritance
// component                      =   base interface for all objects that can be decorated
// concrete component             =   the core object receiving added behavior
// decorator                      =   abstract wrapper that forwards requests to the wrapped object
// concrete decorators            =   add specific behavior before/after delegating to the wrapped object
// stacking decorators            =   multiple decorators can wrap each other to build complex behavior
// open/closed principle          =   classes are open for extension but closed for modification
// runtime flexibility            =   behavior can be changed or extended while the program is running
// contrast with inheritance      =   inheritance adds behavior at compile time; decorators add at runtime
// use cases                      =   UI widgets, stream filters, logging wrappers, encryption layers

// ------------------------------------------------------------
// COMPONENT INTERFACE
// ------------------------------------------------------------
class Message {
public:
    virtual std::string get() = 0;
    virtual ~Message() = default;
};

// ------------------------------------------------------------
// CONCRETE COMPONENT
// ------------------------------------------------------------
class PlainMessage : public Message {
private:
    std::string text;
public:
    PlainMessage(const std::string& t) : text(t) {}

    std::string get() override {
        return text;
    }
};

// ------------------------------------------------------------
// DECORATOR BASE CLASS
// ------------------------------------------------------------
class MessageDecorator : public Message {
protected:
    std::shared_ptr<Message> wrappee;
public:
    MessageDecorator(std::shared_ptr<Message> m) : wrappee(m) {}
};

// ------------------------------------------------------------
// CONCRETE DECORATORS
// ------------------------------------------------------------

// adds brackets around the message
class BracketDecorator : public MessageDecorator {
public:
    BracketDecorator(std::shared_ptr<Message> m) : MessageDecorator(m) {}

    std::string get() override {
        return "[" + wrappee->get() + "]";
    }
};

// converts message to uppercase
class UppercaseDecorator : public MessageDecorator {
public:
    UppercaseDecorator(std::shared_ptr<Message> m) : MessageDecorator(m) {}

    std::string get() override {
        std::string s = wrappee->get();
        for (char& c : s) c = std::toupper(c);
        return s;
    }
};

// adds logging behavior
class LoggingDecorator : public MessageDecorator {
public:
    LoggingDecorator(std::shared_ptr<Message> m) : MessageDecorator(m) {}

    std::string get() override {
        std::cout << "[LOG] Accessing message\n";
        return wrappee->get();
    }
};

// ------------------------------------------------------------
// WHY DECORATOR IS USEFUL
// ------------------------------------------------------------
// - avoids subclass explosion (e.g., ButtonWithBorderAndShadow)
// - decorators can be combined in any order
// - behavior can be added or removed at runtime
// - ideal for I/O streams, formatting, encryption, compression
// - follows open/closed principle
// - does not modify existing classes

// ------------------------------------------------------------
// EXAMPLE USAGE
// ------------------------------------------------------------
int main() {
    std::shared_ptr<Message> msg = std::make_shared<PlainMessage>("hello world");

    msg = std::make_shared<BracketDecorator>(msg);
    msg = std::make_shared<UppercaseDecorator>(msg);
    msg = std::make_shared<LoggingDecorator>(msg);

    std::cout << msg->get() << "\n";

    return 0;
}
