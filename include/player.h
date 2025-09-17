#ifndef PLAYER_H
#define PLAYER_H

#include "raylib.h"
#include "raymath.h"
#include "block.h"
#include "game.h"
#include "enums.h"
#include <memory>
#include <string>
#include <vector>

class player{
    private:
    std::vector<block*> playerParts;
    block *playerHead;
    bool allowedInput;


    public:

    player(Vector2 spawnPosition = Vector2One());
    ~player();

    void allowPlayerInput();
    void disallowPlayerInput();

    inline bool isAllowedInput(){return allowedInput;}
    block* getBlock(block* b);
    std::vector<block*> getPlayerBlocks();
    
};

#endif