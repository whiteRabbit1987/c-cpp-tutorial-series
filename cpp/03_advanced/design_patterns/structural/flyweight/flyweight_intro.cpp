// flyweight_intro.cpp
#include <iostream>
#include <string>
#include <unordered_map>

// flyweight pattern        =   share common intrinsic data between many objects to reduce memory usage
// intrinsic state          =   data that is shared and does not change (e.g., sprite image)
// extrinsic state          =   data supplied from outside and varies per object (e.g., position)
// sprite example           =   many game objects use the same sprite image; flyweight stores it once
// memory reduction         =   thousands of objects share one heavy resource instead of duplicating it

class Sprite {
private:
    std::string texture;   // intrinsic shared data
public:
    Sprite(const std::string& tex) : texture(tex) {}

    void draw(int x, int y) {
        std::cout << "Drawing sprite '" << texture
                  << "' at (" << x << ", " << y << ")\n";
    }
};

class SpriteFactory {
private:
    std::unordered_map<std::string, Sprite*> sprites;
public:
    Sprite* getSprite(const std::string& texture) {

        // flyweight check      =   if the sprite does not exist yet, create it once
        //                          ensures intrinsic shared data is reused instead of duplicated
        if (!sprites.count(texture))
            sprites[texture] = new Sprite(texture);

        return sprites[texture];
    }
};

int main() {
    SpriteFactory factory;

    Sprite* enemySprite = factory.getSprite("enemy.png");
    Sprite* enemySprite2 = factory.getSprite("enemy.png"); // shared

    enemySprite->draw(10, 20);
    enemySprite2->draw(30, 40);

    return 0;
}
