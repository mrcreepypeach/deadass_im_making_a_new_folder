#ifndef GAME_H
#define GAME_H

#include "raylib.h"
#include "block.h"
#include "player.h"

#include <string>
#include <map>
#include <vector>

class game{
    private:
    enum status{
        STARTED,
        PAUSED,
        TITLE
    };    

    status GameStatus {TITLE};
    const std::map<status, std::string> gameDisplayStrings {
        {TITLE, std::string("Press space to begin")},
        {STARTED, std::string("SNAKE")},
        {PAUSED, std::string("Press space to continue")}
    };

    const int centeredXText = (GetScreenWidth() / 2);
    const int centeredYText = (GetScreenHeight() / 2) + GetScreenHeight() / 10;
    
    // game data related things

    
    std::vector<block> currentApples {};

    public:

    game();
    ~game();

    

    // Getters and Setters

    inline void togglePause(){
        if (GameStatus == TITLE){return;}

        if (GameStatus == PAUSED){
            GameStatus = STARTED;
        }
        else{
            GameStatus = PAUSED;
        }
    }
    inline status getStatus(){return GameStatus;}
    inline void setStatus(status NewStat){GameStatus = NewStat;}

    // Not inline functions

    void displayGame();

};



#endif