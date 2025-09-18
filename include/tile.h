#ifndef TILE.H
#define TILE.H

#include "raylib.h"

class tile{

    private:
    enum tile_types{
        EMPTY,
        BORDER,
        OBSTACLE
    };

    

    public:

    tile();
    ~tile();

    inline void draw(){ // this is for debug to show where tiles are when generated
        DrawRectangleLines()
    }
};

#endif