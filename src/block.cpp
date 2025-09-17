#include <iostream>
#include "raylib.h"
#include "raymath.h"
#include "block.h"
#include "enums.h"
#include <vector>

block::block(Vector2 p, BLOCK_TYPE t, Vector2 s, Color c)
{
    block::position = p;
    block::size = s;
    block::color = c;
    block::type = t;
    
    std::cout << this << " block initialized\n";
}

block::~block()
{
    std::cout << this << " block deleted from memory\n";
}

inline void block::draw()
{
    DrawRectangleV(this->position, this->size, this->color);
}

std::vector<block *> block::checkCollision(std::vector<block *> items)
{
    std::vector<block *> result;
    for (block *b : items){
        
        if (Vector2Distance(b->position, this->position) <= 1){
            result.push_back(b);
        }
    }
    
    return result;
}
