#pragma once

#include "raylib.h"
#include "block.h"
#include "game.h"
#include "enums.h"
#include <memory>
#include <vector>

class player{
    private:
    std::vector<block*> playerParts;
    block *playerHead;


    public:

    player();
    ~player();

    std::vector<block*> getPlayerBlocks();
    
};