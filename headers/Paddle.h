#pragma once
#include "GameConfig.h"

class Paddle { 
    private: 
        double x,y,width,height;  
        double speed = PADDLE_SPEED;
    public:
        Paddle(double x,double y);
        void setY(double y); //For moving the paddle
        void Draw(); //For drawing the paddle
        void setSpeed(double speed); //For setting the paddle speed
        double getSpeed(); //For getting the paddle speed
};