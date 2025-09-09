#include "raylib.h"

#include "block.h"
#include "enums.h"
#include "waiter.h"
#include "player.h"

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

    waiter blockspawn = waiter();
    waiter blockdelete = waiter();
    blockspawn.wait(.01);

    player Player = player();

    while (!WindowShouldClose()){
        // perform calculations and such before drawing

        for (block *b : blocks){
            if (blocks.capacity() > 3 && blockdelete.update()){
                blocks.pop_back();
                delete b;
                blockdelete.wait(5);
            }
        }

        Vector2 randomSize = {static_cast<float>(GetRandomValue(randomMinS, randomMaxS)), static_cast<float>(GetRandomValue(randomMinS, randomMaxS))};
        Vector2 randomPos = {static_cast<float>(GetRandomValue(1, WIN_WIDTH)), static_cast<float>(GetRandomValue(1, WIN_HEIGHT))};

        

        if (blockspawn.update()){
            block *NewBlock = new block(randomPos, SNAKE_BODY, randomSize, WHITE);
            blocks.push_back(NewBlock);
            blockspawn.wait(1);
        }

        // draw to screen
        BeginDrawing();

        ClearBackground(BLACK);

        for (block *b : blocks) {
            b->draw();
        }

        EndDrawing();
    }

    return 0;
}

