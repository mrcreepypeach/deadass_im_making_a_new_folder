#include "raylib.h"

#include "block.h"
#include "enums.h"
#include "waiter.h"
#include "player.h"
#include "game.h"

#include <iostream>
#include <vector>

const int WIN_WIDTH {1280};
const int WIN_HEIGHT {800};
const char WIN_NAME[] {"Test"};

const int randomMinS {10};
const int randomMaxS {20};

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

        game Game = game(); // initalize game knowledge

       

        // draw to screen
        BeginDrawing();

        ClearBackground(BLACK);

        EndDrawing();
    }

    return 0;
}

