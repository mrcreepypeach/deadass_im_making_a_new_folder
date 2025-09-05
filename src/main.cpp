#include "raylib.h"

#include "block.h"
#include "enums.h"

#include <iostream>
#include <vector>

const int WIN_WIDTH = 1280;
const int WIN_HEIGHT = 800;
const char WIN_NAME[] = "Test";

const int randomMinS = 10;
const int randomMaxS = 20;

int main(){
    
    static std::vector<block*> blocks = {};

    InitWindow(WIN_WIDTH, WIN_HEIGHT, WIN_NAME);
    SetTargetFPS(60);

    while (!WindowShouldClose()){
        // perform calculations and such before drawing
        
        static int timer = GetTime();

        for (block *b : blocks){
            if (blocks.capacity() > 3){
                blocks.pop_back();
                delete b;
            }
        }

        Vector2 randomSize = {static_cast<float>(GetRandomValue(randomMinS, randomMaxS)), static_cast<float>(GetRandomValue(randomMinS, randomMaxS))};
        Vector2 randomPos = {static_cast<float>(GetRandomValue(1, WIN_WIDTH)), static_cast<float>(GetRandomValue(1, WIN_HEIGHT))};

        block *NewBlock = new block(randomPos, randomSize, WHITE, SNAKE_BODY);
        

        blocks.push_back(NewBlock);

        // draw to screen
        BeginDrawing();

        ClearBackground(BLACK);

        for (block *b : blocks) {
            b->draw();
        }

        if (GetTime() - timer > 3){
            NewBlock->draw();
            timer = GetTime();
        }

        EndDrawing();
    }

    return 0;
}

