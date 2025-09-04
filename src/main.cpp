#include "raylib.h"

#include "block.h"
#include "enums.h"

#include <iostream>

const int WIN_WIDTH = 1280;
const int WIN_HEIGHT = 800;
const char WIN_NAME[] = "Test";

int main(){
    
    InitWindow(WIN_WIDTH, WIN_HEIGHT, WIN_NAME);


    while (!WindowShouldClose()){
        // perform calculations and such before drawing

        

        // draw to screen
        BeginDrawing();

        ClearBackground(BLACK);

        EndDrawing();
    }

    return 0;
}

/*
int main(){
    std::cout << "Main process start";
    
    SetConfigFlags(FLAG_WINDOW_HIGHDPI);
    SetTargetFPS(60);

    InitWindow(WIN_WIDTH, WIN_HEIGHT, WIN_NAME);
    
    while (!WindowShouldClose()){

        BeginDrawing();

        ClearBackground(BLACK);

        EndDrawing();

    }
    std::cout << "\nProcess end";
    return 0;
}
    */