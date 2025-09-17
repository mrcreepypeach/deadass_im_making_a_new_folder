#include "raylib.h"
#include "raymath.h"

#include "block.h"
#include "enums.h"
#include "waiter.h"
#include "player.h"
#include "game.h"

#include <iostream>
#include <vector>
#include <string>

const int WIN_WIDTH {1280};
const int WIN_HEIGHT {800};
const char WIN_NAME[] {"Test"};

const int randomMinS {10};
const int randomMaxS {20};

int main(){

    InitWindow(WIN_WIDTH, WIN_HEIGHT, WIN_NAME);
    SetTargetFPS(60);

    game Game = game(); // initalize game knowledge

    while (!WindowShouldClose()){
        // perform calculations and such before drawing
       
        // draw to screen
        BeginDrawing();

        ClearBackground(BLACK);
        Game.displayGame();

        EndDrawing();
    }

    return 0;
}

