#pragma once
#include "GameConfig.h"

class Paddle {
    private:
        int x,y,width,height;
    public:
        Paddle(int x,int y);
        void setY(int y);
        void Draw();
};