// flyweight_overview.cpp
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

// flyweight pattern                =   minimize memory usage by sharing intrinsic data across many objects
// intrinsic state                  =   immutable, shared data stored inside the flyweight (e.g., sprite image)
// extrinsic state                  =   per‑object data supplied externally (e.g., position, rotation, scale)
// sprite usage                     =   thousands of game objects share one sprite texture
// memory savings                   =   prevents duplication of large assets in memory
// factory role                     =   ensures flyweights are reused instead of recreated
// general usage                    =   text rendering, particle systems, sprites, icons, trees, bullets
// when to use                      =   when many objects share identical data but differ in small external details

// ------------------------------------------------------------
// FLYWEIGHT (shared object)
// ------------------------------------------------------------
class Sprite {
private:
    std::string texture;   // intrinsic shared data
public:
    Sprite(const std::string& tex) : texture(tex) {}

    void draw(int x, int y, float scale, float rotation) {
        std::cout << "Drawing sprite '" << texture
                  << "' at (" << x << ", " << y
                  << ") scale=" << scale
                  << " rotation=" << rotation << "\n";
    }
};

// ------------------------------------------------------------
// FLYWEIGHT FACTORY
// ------------------------------------------------------------
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

// ------------------------------------------------------------
// GAME OBJECT USING FLYWEIGHT
// ------------------------------------------------------------
class GameObject {
private:
    Sprite* sprite;     // shared intrinsic data
    int x, y;           // extrinsic state
    float scale;
    float rotation;
public:
    GameObject(Sprite* s, int x, int y, float scale, float rotation)
        : sprite(s), x(x), y(y), scale(scale), rotation(rotation) {}

    void draw() {
        sprite->draw(x, y, scale, rotation);
    }
};

// ------------------------------------------------------------
// EXAMPLE: MANY OBJECTS USING FEW SPRITES
// ------------------------------------------------------------
int main() {
    SpriteFactory factory;

    Sprite* enemySprite = factory.getSprite("enemy.png");
    Sprite* treeSprite  = factory.getSprite("tree.png");

    std::vector<GameObject> objects;
    objects.emplace_back(enemySprite, 10, 20, 1.0f, 0.0f);
    objects.emplace_back(enemySprite, 30, 40, 1.2f, 15.0f);
    objects.emplace_back(enemySprite, 50, 60, 0.8f, -10.0f);

    objects.emplace_back(treeSprite, 100, 200, 2.0f, 0.0f);
    objects.emplace_back(treeSprite, 120, 220, 2.0f, 5.0f);

    for (auto& obj : objects)
        obj.draw();

    return 0;
}
