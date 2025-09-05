#pragma once
#include "raylib.h"

class waiter{
    private:
    double timer; // holds the time
    double targetTime; // the time to wait

    public:

    waiter(){
        timer = 0.0;
        targetTime = 0.0;
    }

    void wait(double seconds){

        timer = GetFrameTime();
        targetTime = seconds;
    }

    bool update(){
        timer += GetFrameTime();
        if (targetTime >= timer){
            return false;
        }
        return true;
    }

};