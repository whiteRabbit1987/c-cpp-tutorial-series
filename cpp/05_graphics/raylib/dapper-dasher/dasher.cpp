#include "raylib.h"

struct AnimData{
    Rectangle rec;
    Vector2 pos;
    int frame;
    float updateTime;
    float runningTime;
};

bool isOnGround(AnimData data, int windowHeight){
    return data.pos.y >= (windowHeight - data.rec.height);
}

void updateAnimationFrame(AnimData &data, const float dT, int maxFrame){
    // update running time
    data.runningTime += dT;
    if(data.runningTime >= data.updateTime){
        data.runningTime = 0.0;
        // update animation frame
        data.rec.x = data.frame * data.rec.width;
        data.frame++;
        if(data.frame > maxFrame){
            data.frame = 0;
        }
    }
}

int main(){

    // window variables
    const int windowDimensions[2] = {512, 380};
    const char * title{"David's Dasher"};

    // initalize the window
    InitWindow(windowDimensions[0], windowDimensions[1], title);

    // acceleration due to gravity (pixels/s) per second
    const int gravity{1'000};

    // nebula variables
    Texture2D nebula = LoadTexture("textures/12_nebula_spritesheet.png");
    const int nebulaFrame{7};
    const int sizeOfNebulae{3};

    // AnimData for nebula
    AnimData nebulae[sizeOfNebulae]{}; 

    for(int i = 0; i < sizeOfNebulae; i++){
        nebulae[i].rec.x = 0.0;
        nebulae[i].rec.y = 0.0;
        nebulae[i].rec.width = nebula.width/8;
        nebulae[i].rec.height = nebula.height/8;
        nebulae[i].pos.x = windowDimensions[0] + (i * 300);
        nebulae[i].pos.y = windowDimensions[1] - nebula.height/8;
        nebulae[i].frame = 0;
        nebulae[i].runningTime = 0.0;
        nebulae[i].updateTime = 1.0/16.0;
    }

    float finishLine{ nebulae[sizeOfNebulae - 1].pos.x };

    // nebula X velocity (pixels/second)
    int nebVel{-200};

    // scarfy variables
    Texture2D scarfy = LoadTexture("textures/scarfy.png");
    const int scarfyFrame{5};
    AnimData scarfyData;
    scarfyData.rec.width = scarfy.width/6;
    scarfyData.rec.height = scarfy.height;
    scarfyData.rec.x = 0;
    scarfyData.rec.y = 0;
    scarfyData.pos.x = windowDimensions[0]/2 - scarfyData.rec.width/2;
    scarfyData.pos.y = windowDimensions[1] - scarfyData.rec.height;

    //animation frame
    scarfyData.frame = 0;
    // amount of time before we update the animation frame
    scarfyData.updateTime = 1.0/12.0;
    scarfyData.runningTime = 0;

    // is the rectangle in the air?
    bool isInAir{false};
    // jump velocity (pixels per second)
    const int jumpVel{-600};

    int velocity{0};

    // Backgounds
    Texture2D background = LoadTexture("textures/far-buildings.png");
    float bgX{};
    Texture2D midground = LoadTexture("textures/back-buildings.png");
    float mgX{};
    Texture2D foreground = LoadTexture("textures/foreground.png");
    float fgX{};
   
    bool collision{false};

    SetTargetFPS(60);
    while(!WindowShouldClose()){

        // delta time (time since last frame)
        const float dT{ GetFrameTime() };

        // start drawing
        BeginDrawing();
        ClearBackground(WHITE);

        // Scroll background
        bgX -= 20 *dT;
        if(bgX <= -background.width*2){
            bgX = 0.0;
        }
        // Scroll midground
        mgX -= 40 *dT;
        if(mgX <= -midground.width*2){
            mgX = 0.0;
        }
        // Scroll foreground
        fgX -= 80 *dT;
        if(fgX <= -foreground.width*2){
            fgX = 0.0;
        }

        // draw the background
        Vector2 bg1Pos{bgX, 0.0};
        Vector2 bg2Pos{bgX + background.width*2, 0.0};
        DrawTextureEx(background, bg1Pos, 0.0, 2.0, WHITE);
        DrawTextureEx(background, bg2Pos, 0.0, 2.0, WHITE);
        
        // draw the midground
        Vector2 mgX1Pos{mgX, 0.0};
        Vector2 mgX2Pos{mgX + midground.width*2, 0.0};
        DrawTextureEx(midground, mgX1Pos, 0.0, 2.0, WHITE);
        DrawTextureEx(midground, mgX2Pos, 0.0, 2.0, WHITE);

        // draw the foreground
        Vector2 fgX1Pos{fgX, 0.0};
        Vector2 fgX2Pos{fgX + foreground.width*2, 0.0};
        DrawTextureEx(foreground, fgX1Pos, 0.0, 2.0, WHITE);
        DrawTextureEx(foreground, fgX2Pos, 0.0, 2.0, WHITE);

        // perform ground check
        if(isOnGround(scarfyData, windowDimensions[1])){
            // rectangle is on the ground
            velocity = 0;
            isInAir = false;
        } else {
            // rectangle is in the air
            // apply gravity
            velocity += gravity * dT;
            isInAir = true;
        }

        // jump check
        if(IsKeyPressed(KEY_SPACE) && !isInAir){
            velocity += jumpVel;
        }

        for(int i = 0; i < sizeOfNebulae; i++){
            // update nebula positon
            nebulae[i].pos.x += nebVel * dT;
        }

        // update finsihLine postion
        finishLine += nebVel * dT;

        // update scarfy position
        scarfyData.pos.y += velocity * dT;

        // check if scarfy is already in the air
        if(!isInAir){
            // update scarfys animation frame
            updateAnimationFrame(scarfyData, dT, scarfyFrame);
        }

        for(int i = 0; i < sizeOfNebulae; i++){
            // update nebula animation frame
            updateAnimationFrame(nebulae[i], dT, nebulaFrame);
        }

        for(AnimData nebula : nebulae){
            float pad{50};
            Rectangle nebRec{
                nebula.pos.x + pad,
                nebula.pos.y + pad,
                nebula.rec.width - 2*pad,
                nebula.rec.height - 2*pad
            };
            Rectangle scarfyRec{
                scarfyData.pos.x,
                scarfyData.pos.y,
                scarfyData.rec.width,
                scarfyData.rec.height
            };
            // check for collision
            if(CheckCollisionRecs(nebRec, scarfyRec)){
                collision = true;
            }
        }

        if(collision){
            // loose the game
            DrawText("Game over!", windowDimensions[0]/3, windowDimensions[1]/2, 40, RED);
        } else if (scarfyData.pos.y > finishLine){
            // win the game
            DrawText("You WIN!", windowDimensions[0]/3, windowDimensions[1]/2, 40, RED);
        } else {
            for(int i = 0; i < sizeOfNebulae; i++){
                // draw nebula
                DrawTextureRec(nebula, nebulae[i].rec, nebulae[i].pos, WHITE);
            }

            // draw scarfy
            DrawTextureRec(scarfy, scarfyData.rec, scarfyData.pos, WHITE);
        }

        // stop drawing
        EndDrawing();
    }
    UnloadTexture(scarfy);
    UnloadTexture(nebula);
    UnloadTexture(background);
    UnloadTexture(midground);
    UnloadTexture(foreground);
    CloseWindow();

    return 0;
}
