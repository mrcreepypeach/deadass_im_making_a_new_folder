#pragma once

#include "raylib.h"
#include "enums.h"

class block{
public:
    Vector2 position;
    Vector2 size;
    Color color;
    BLOCK_TYPE type;

    block(Vector2 p, Vector2 s, Color c, BLOCK_TYPE t);
    void draw();
};