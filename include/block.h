#pragma once

#include "raylib.h"
#include "raymath.h"
#include "enums.h"
#include "tile.h"

#include <vector>

class block{
public:
    Vector2 position;
    Vector2 size;
    Color color;
    BLOCK_TYPE type;

    block(Vector2 p, BLOCK_TYPE t, Vector2 s = Vector2One(), Color c = GREEN);
    ~block();
    inline void draw();
    std::vector<block*> checkCollision(std::vector<block*> items);
};