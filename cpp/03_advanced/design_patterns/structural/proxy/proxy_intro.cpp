#include <iostream>
#include <string>

// proxy pattern            =   provide a stand‑in object that controls access to a real object
// virtual proxy            =   delays creation of a heavy object until it is actually needed
// real subject             =   the actual object doing the work
// proxy                    =   same interface as real subject; decides when to create/use it
// problem solved           =   avoid expensive object creation until necessary

class Image {
public:
    virtual void display() = 0;
    virtual ~Image() = default;
};

class RealImage : public Image {
private:
    std::string filename;
public:
    RealImage(const std::string& f) : filename(f) {
        std::cout << "Loading image from disk: " << filename << "\n";
    }

    void display() override {
        std::cout << "Displaying image: " << filename << "\n";
    }
};

class ImageProxy : public Image {
private:
    std::string filename;
    RealImage* real = nullptr;
public:
    ImageProxy(const std::string& f) : filename(f) {}

    void display() override {
        if (!real)
            real = new RealImage(filename);   // virtual proxy creates object lazily
        real->display();
    }
};

int main() {
    Image* img = new ImageProxy("photo.png");

    std::cout << "Image created but not loaded yet\n";
    img->display();   // loads only now

    delete img;
    return 0;
}
