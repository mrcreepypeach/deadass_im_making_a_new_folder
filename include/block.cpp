#include "raylib.h"
#include "block.h"
#include "enums.h"

block::block(Vector2 p, Vector2 s, Color c, BLOCK_TYPE t)
{
    block::position = p;
    block::size = s;
    block::color = c;
    block::type = t;
}

void block::draw()
{
    DrawRectangleV(block::position, block::size, block::color);
}
