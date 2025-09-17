#include "raylib.h"

#include "game.h"
#include "player.h"
#include "block.h"
#include "waiter.h"

#include <iostream>
#include <map>
#include <string>
#include <vector>

game::game(){
    std::cout << "Game init\n\n";
}
game::~game(){
    std::cout << "Game destroyed\n\n";
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



        }
    }
}