#ifndef GAME_H
#define GAME_H

#include "raylib.h"
#include "block.h"
#include "player.h"
#include "tile.h"

#include <string>
#include <memory>
#include <map>
#include <vector>

/// @brief Base game class which holds current game objects and data, including the current player

class game{
    public:

    enum status{
        STARTED,
        PAUSED,
        TITLE
    };

    bool active = false;

    player Player = player();

    game();
    ~game();

    // Getters and Setters

/// @brief Toggles the current state of the game. Does nothing if GameStatus is TITLE.
    inline void togglePause(){
        if (GameStatus == TITLE){return;}

        if (GameStatus == PAUSED){
            GameStatus = STARTED;
        }
        else{
            GameStatus = PAUSED;
        }
    }
    /// @brief Obtain current game status.
    /// @return status enum
    inline status getStatus() const {return GameStatus;}

    /// @brief Obtains a reference to current apples on the map
    /// @return reference to a vector of apple blocks
    inline std::map<block, tile>& getApples() {return currentApples;}
    
    /// @brief Change the current status of the game
    /// @param NewStat status to change to
    inline void setStatus(status NewStat){GameStatus = NewStat;}

    inline const std::vector<std::vector<std::unique_ptr<tile>>>& getMap() const {return Map;} // this causes an error for some reason

    // Not inline functions

    /// @brief Generate a map layout for the game with given parameters
    /// @param size Size of the map (default is 20x20)
    /// @param borderDepth How deep the border for the map will generate (default is 1)
    /// @param hasObstacles Says if the map should generate tiles of obstacles (default is false)
    void createMap(Vector2 size = {20,20}, int borderDepth = 1, bool hasObstacles = false);

    /// @brief Draw current game objects to the screen depending on GameStatus
    void displayGame();

    private:
    
    status GameStatus {TITLE};
    const std::map<status, std::string> gameDisplayStrings {
        {TITLE, std::string("Press space to begin")},
        {STARTED, std::string("SNAKE")},
        {PAUSED, std::string("Press space to continue")}
    };

    const int centeredXText = (GetScreenWidth() / 2);
    const int centeredYText = (GetScreenHeight() / 2) - GetScreenHeight() / 10;
    
    // game data related things

    std::vector<std::vector<std::unique_ptr<tile>>> Map {}; // a 2d vector of smart pointers to tiles

    std::map<block, tile> currentApples {}; // current apples on the map located in a dictionary map

};



#endif