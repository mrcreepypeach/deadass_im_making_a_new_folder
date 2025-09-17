#include "raylib.h"
#include "game.h"
#include "player.h"
#include "block.h"
#include "waiter.h"

#include <map>
#include <string>
#include <vector>

void game::displayGame()
{
    switch(GameStatus){
        case TITLE:
        {
            DrawText(gameDisplayStrings.at(TITLE).c_str(), centeredXText, centeredYText, 10, WHITE);

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
        
    }
}