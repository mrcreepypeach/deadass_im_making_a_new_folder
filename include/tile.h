#ifndef TILE_H

#define TILE_H

#include "raylib.h"

#include <iostream>

class tile{

    public:

    enum class tile_type{
        EMPTY,
        BORDER,
        OBSTACLE
    };

    tile();
    ~tile();

    inline tile_type getType() const {return Type;}
    inline void setType(tile_type t){Type = t;}
    inline Vector2 getPosition() const {return position;}
    inline void setPosition(Vector2 p){position = p;}

    inline void draw() const { // this is for debug to show where tiles are when generated
        Color c = {WHITE};
        switch(getType()){
            case tile_type::BORDER: c = RED; break;
            case tile_type::OBSTACLE: c = BLUE; break;
        }
        DrawRectangleLines(position.x, position.y, size.x, size.y, c);
        std::cout << this << " drawn\n";
    }

    private:
    
    // tile type
    tile_type Type {tile_type::EMPTY};

    Vector2 position {1,1};
    Vector2 size {10,10};
};

#endif