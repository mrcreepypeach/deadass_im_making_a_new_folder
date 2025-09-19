#include "raylib.h"

#include "game.h"
#include "player.h"
#include "block.h"
#include "waiter.h"

#include <iostream>
#include <memory>
#include <map>
#include <string>
#include <vector>

game::game(){
    std::cout << "Game init\n\n";
}
game::~game(){
    std::cout << "Game destroyed\n\n";
}

void game::createMap(Vector2 size, int borderDepth, bool hasObstacles)
{
    if (active){return;}
    active = true;
    
    // change the size of the array to the directed size

    if (size.x > 0 && size.y > 0){
        Map.resize(size.x);
        for (int i = 0; i < size.x; i++){
            Map[i].resize(size.y);
        }
    }

    // initialize every entry in the array with an empty tile

    for (int i = 0; i < size.x; i++){
        for (int j = 0; j < size.y; j++){
            std::unique_ptr<tile> newTile;
            Map[i][j] = std::make_unique<tile>();
            tile *curTile = Map[i][j].get();

            curTile->setPosition(Vector2 {curTile->getPosition().x + 10, curTile->getPosition().y + 10});
            curTile->setType(tile::tile_type::EMPTY);
            
        }
    }

    // Fill borders

    for (int i = 0; i < size.x; i++){
        for (int j = 0; j < size.y; j++){
            if ((i < 1 && j >= 0) || (i >= 0 && j < 1)){
                Map[i][j].get()->setType(tile::tile_type::BORDER);
            }
        }
    }
}

void game::displayGame()
{
    // this probably isnt optimal but idc cuz i dont feel like rewriting it

    switch(GameStatus){
        case TITLE:
        {
            DrawText(gameDisplayStrings.at(TITLE).c_str(), centeredXText, centeredYText, 10, WHITE);

            // maybe i'll have cool shit happening on the title later idk
        }
        case PAUSED:
        {
            DrawText(gameDisplayStrings.at(PAUSED).c_str(), centeredXText, centeredYText, 10, WHITE);
        }
        case STARTED:
        {
            DrawText(gameDisplayStrings.at(STARTED).c_str(), centeredXText, centeredYText, 5, WHITE);
        }
    }

    if (IsKeyPressed(KEY_SPACE)){

        switch(GameStatus){
            case TITLE:
            {
                this->setStatus(game::STARTED);
                break;
            }
            case PAUSED:
            {
                this->togglePause();
                break;
            }
            case STARTED:
            {
                this->togglePause();
                break;
            }
        }

        if (this->getStatus() != TITLE){

            // Computing where everything ingame should be
            // Start with the map

            for (int i = 0; i < Map.size(); i++){
                for (int j = 0; j < Map[i].size(); j++){
                    Map[i][j].get()->draw(); // for debug
                }
            }



        }
    }
}