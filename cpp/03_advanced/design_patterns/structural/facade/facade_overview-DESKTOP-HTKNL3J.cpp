#include <iostream>
#include <string>

// facade pattern                  =   provide a unified, simplified interface to a complex subsystem
//                                   hides internal details and reduces dependency on subsystem classes
// subsystem complexity            =   many classes, many steps, strict ordering, error handling
// facade role                     =   orchestrates subsystem calls in correct order
// client benefit                  =   interacts with one simple object instead of many
// loose coupling                  =   client is shielded from subsystem changes
// use cases                       =   startup sequences, media players, network stacks, database layers
// hiding complexity               =   facade exposes only what the client needs, nothing more
// general usage                   =   wrap messy APIs, simplify workflows, enforce correct usage patterns

// ------------------------------------------------------------
// SUBSYSTEM A — AUDIO ENGINE
// ------------------------------------------------------------
class AudioDecoder {
public:
    void decode(const std::string& file) {
        std::cout << "Decoding audio file: " << file << "\n";
    }
};

class AudioMixer {
public:
    void mix() {
        std::cout << "Mixing audio streams\n";
    }
};

class AudioOutput {
public:
    void play() {
        std::cout << "Playing audio\n";
    }
};

// ------------------------------------------------------------
// SUBSYSTEM B — VIDEO ENGINE
// ------------------------------------------------------------
class VideoDecoder {
public:
    void decode(const std::string& file) {
        std::cout << "Decoding video file: " << file << "\n";
    }
};

class VideoRenderer {
public:
    void render() {
        std::cout << "Rendering video frames\n";
    }
};

// ------------------------------------------------------------
// FACADE — MEDIA PLAYER
// ------------------------------------------------------------
class MediaPlayerFacade {
private:
    AudioDecoder audioDec;
    AudioMixer audioMix;
    AudioOutput audioOut;

    VideoDecoder videoDec;
    VideoRenderer videoRen;

public:
    void playMedia(const std::string& file) {
        // hide complexity: client sees only one method
        audioDec.decode(file);
        audioMix.mix();
        audioOut.play();

        videoDec.decode(file);
        videoRen.render();
    }

    void playAudioOnly(const std::string& file) {
        audioDec.decode(file);
        audioMix.mix();
        audioOut.play();
    }

    void playVideoOnly(const std::string& file) {
        videoDec.decode(file);
        videoRen.render();
    }
};

// ------------------------------------------------------------
// WHY FACADE IS USEFUL
// ------------------------------------------------------------
// - hides subsystem complexity
// - prevents client from misusing subsystem order
// - reduces coupling between client and subsystem
// - subsystem can change internally without affecting client
// - simplifies large APIs into a few easy methods
// - ideal for startup sequences, media pipelines, network stacks

// ------------------------------------------------------------
// EXAMPLE USAGE
// ------------------------------------------------------------
int main() {
    MediaPlayerFacade player;

    player.playMedia("movie.mp4");
    player.playAudioOnly("song.mp3");
    player.playVideoOnly("clip.mkv");

    return 0;
}
