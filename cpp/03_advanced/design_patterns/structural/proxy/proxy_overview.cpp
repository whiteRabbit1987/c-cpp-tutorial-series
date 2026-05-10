#include <iostream>
#include <string>

// proxy pattern                    =   control access to another object through a stand‑in
// problem solved                   =   manage expensive creation, remote access, or restricted access
// virtual proxy                    =   delays creation of heavy objects until needed
// protective proxy                 =   controls access based on permissions or rules
// remote proxy                     =   represents an object located on another machine
// interface matching               =   proxy and real subject share the same interface
// client benefit                   =   client interacts with proxy exactly like the real object
// general usage                    =   lazy loading, caching, access control, network stubs, logging wrappers

// ------------------------------------------------------------
// SUBJECT INTERFACE
// ------------------------------------------------------------
class Document {
public:
    virtual void open() = 0;
    virtual void edit(const std::string& text) = 0;
    virtual ~Document() = default;
};

// ------------------------------------------------------------
// REAL SUBJECT
// ------------------------------------------------------------
class RealDocument : public Document {
private:
    std::string filename;
public:
    RealDocument(const std::string& f) : filename(f) {
        std::cout << "Loading document: " << filename << "\n";
    }

    void open() override {
        std::cout << "Opening document: " << filename << "\n";
    }

    void edit(const std::string& text) override {
        std::cout << "Editing '" << filename << "' with: " << text << "\n";
    }
};

// ------------------------------------------------------------
// VIRTUAL PROXY — LAZY LOADING
// ------------------------------------------------------------
class DocumentProxy : public Document {
private:
    std::string filename;
    RealDocument* real = nullptr;
public:
    DocumentProxy(const std::string& f) : filename(f) {}

    void open() override {
        if (!real)
            real = new RealDocument(filename);   // virtual proxy creates on demand
        real->open();
    }

    void edit(const std::string& text) override {
        if (!real)
            real = new RealDocument(filename);
        real->edit(text);
    }
};

// ------------------------------------------------------------
// PROTECTIVE PROXY — ACCESS CONTROL
// ------------------------------------------------------------
class SecureDocumentProxy : public Document {
private:
    RealDocument* real;
    bool canEdit;
public:
    SecureDocumentProxy(RealDocument* doc, bool permission)
        : real(doc), canEdit(permission) {}

    void open() override {
        real->open();
    }

    void edit(const std::string& text) override {
        if (!canEdit) {
            std::cout << "Access denied: insufficient permissions\n";
            return;
        }
        real->edit(text);
    }
};

// ------------------------------------------------------------
// WHY PROXY IS USEFUL
// ------------------------------------------------------------
// - virtual proxy: avoid expensive object creation until needed
// - protective proxy: enforce permissions and security rules
// - remote proxy: represent remote objects locally
// - logging proxy: record calls without modifying real subject
// - caching proxy: store results to avoid repeated expensive work
// - client code stays unchanged because proxy matches the interface

// ------------------------------------------------------------
// EXAMPLE USAGE
// ------------------------------------------------------------
int main() {
    Document* lazyDoc = new DocumentProxy("report.txt");
    lazyDoc->open();   // loads only now

    RealDocument* real = new RealDocument("secure.txt");
    Document* secure = new SecureDocumentProxy(real, false);

    secure->open();
    secure->edit("new content");   // blocked

    delete lazyDoc;
    delete secure;
    delete real;
    return 0;
}
