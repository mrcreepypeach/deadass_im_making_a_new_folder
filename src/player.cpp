#include "player.h"

#include "raylib.h"
#include "block.h"
#include "game.h"
#include "enums.h"
#include <vector>
#include <memory>

player::player(Vector2 spawnPosition = Vector2One())
{
    this->playerHead = new block(spawnPosition, SNAKE_HEAD);
    this->allowedInput = true;
}

player::~player(){

}

void player::allowPlayerInput(){this->allowedInput = true;}

void player::disallowPlayerInput(){this->allowedInput = false;}

block *player::getBlock(block *b)
{
    for (block* a : this->playerParts){
        if (a == b){return b;}
    }
    
    return nullptr;
}

std::vector<block *> player::getPlayerBlocks(){return this->playerParts;}