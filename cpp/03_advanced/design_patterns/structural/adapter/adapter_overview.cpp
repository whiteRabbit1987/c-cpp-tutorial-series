// adapter_overview.cpp
// Structural Pattern: Adapter
// This file demonstrates:
// 1. The problem Adapters solve
// 2. Object Adapter (composition)
// 3. Class Adapter (multiple inheritance)
// 4. Why adapters are useful in real systems

#include <iostream>

// ------------------------------------------------------------
// 1. Existing incompatible class (Adaptee)
// ------------------------------------------------------------
class OldAudioSystem {
public:
    void playOldFormat(const std::string& file) {
        std::cout << "[OldAudioSystem] Playing old audio: " << file << "\n";
    }
};

// ------------------------------------------------------------
// 2. Target interface expected by new code
// ------------------------------------------------------------
class IAudioPlayer {
public:
    virtual void play(const std::string& file) = 0;
    virtual ~IAudioPlayer() = default;
};

// ------------------------------------------------------------
// 3. Object Adapter (uses composition)
// ------------------------------------------------------------
class AudioAdapterObject : public IAudioPlayer {
private:
    OldAudioSystem& oldSystem;
public:
    AudioAdapterObject(OldAudioSystem& sys) : oldSystem(sys) {}

    void play(const std::string& file) override {
        oldSystem.playOldFormat(file);
    }
};

// ------------------------------------------------------------
// 4. Class Adapter (uses multiple inheritance)
// Note: Only works if you can inherit from the adaptee.
// ------------------------------------------------------------
class AudioAdapterClass : public IAudioPlayer, private OldAudioSystem {
public:
    void play(const std::string& file) override {
        playOldFormat(file);
    }
};

// ------------------------------------------------------------
// 5. Why Adapters matter (practical notes)
// ------------------------------------------------------------
// - They allow you to reuse existing code without modifying it.
// - They isolate incompatible interfaces.
// - They help integrate third-party libraries.
// - They reduce refactoring cost in large systems.
// - They support gradual migration from old APIs to new APIs.

// ------------------------------------------------------------
// 6. Example usage
// ------------------------------------------------------------
int main() {
    OldAudioSystem legacy;

    // Object adapter
    AudioAdapterObject objectAdapter(legacy);
    objectAdapter.play("song.wav");

    // Class adapter
    AudioAdapterClass classAdapter;
    classAdapter.play("track.mp3");

    return 0;
}
// use case examples        =   integrating legacy systems (old APIs wrapped for new code)
//                             third‑party libraries (incompatible interfaces adapted to your own)
//                             GUI frameworks (adapting event systems or widgets)
//                             file format converters (old reader adapted to new parser)
//                             hardware abstraction (different device APIs unified)
//                             game engines (adapting old asset loaders to new pipelines)
