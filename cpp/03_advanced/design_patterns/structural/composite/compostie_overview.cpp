// composite_overview.cpp
// Composite Pattern — Extensive Overview
// Demonstrates:
// - Hierarchical structures
// - Treating leaf and composite uniformly
// - Redesigning a system using Composite
// - Multiple component types
// - Nested composites
// - Realistic usage scenarios

#include <iostream>
#include <vector>
#include <memory>
#include <string>

// ------------------------------------------------------------
// COMPONENT INTERFACE
// ------------------------------------------------------------
class FileSystemNode {
public:
    virtual void display(int indent = 0) = 0;
    virtual ~FileSystemNode() = default;
protected:
    void printIndent(int indent) {
        for (int i = 0; i < indent; ++i)
            std::cout << "  ";
    }
};

// ------------------------------------------------------------
// LEAF NODES
// ------------------------------------------------------------
class File : public FileSystemNode {
private:
    std::string name;
public:
    File(const std::string& n) : name(n) {}

    void display(int indent = 0) override {
        printIndent(indent);
        std::cout << "- File: " << name << "\n";
    }
};

class ImageFile : public FileSystemNode {
private:
    std::string name;
public:
    ImageFile(const std::string& n) : name(n) {}

    void display(int indent = 0) override {
        printIndent(indent);
        std::cout << "- Image: " << name << "\n";
    }
};

// ------------------------------------------------------------
// COMPOSITE NODE
// ------------------------------------------------------------
class Folder : public FileSystemNode {
private:
    std::string name;
    std::vector<std::shared_ptr<FileSystemNode>> children;
public:
    Folder(const std::string& n) : name(n) {}

    void add(const std::shared_ptr<FileSystemNode>& node) {
        children.push_back(node);
    }

    void display(int indent = 0) override {
        printIndent(indent);
        std::cout << "+ Folder: " << name << "\n";
        for (auto& c : children)
            c->display(indent + 1);
    }
};

// ------------------------------------------------------------
// REDESIGNING WITH COMPOSITE
// ------------------------------------------------------------
// Without Composite:
//   - You would need separate code paths for files vs folders.
//   - You would manually recurse folder structures.
//   - You would duplicate logic for each type.
//
// With Composite:
//   - File and Folder share the same interface.
//   - You treat everything as FileSystemNode.
//   - Recursion is built into the structure.
//   - Adding new node types is easy.

// ------------------------------------------------------------
// EXAMPLE USAGE
// ------------------------------------------------------------
int main() {
    auto root = std::make_shared<Folder>("root");
    auto docs = std::make_shared<Folder>("documents");
    auto pics = std::make_shared<Folder>("pictures");

    auto file1 = std::make_shared<File>("notes.txt");
    auto file2 = std::make_shared<File>("todo.txt");
    auto img1 = std::make_shared<ImageFile>("photo.png");

    docs->add(file1);
    docs->add(file2);
    pics->add(img1);

    root->add(docs);
    root->add(pics);

    root->display();
    return 0;
}
