#pragma once
#include "GameConfig.h"
#include "Paddle.h"

class Player{
    private:
        int x,y;
        int score;
        Paddle paddle;
    public:
        Player();
        Player(int x,int y);
        void Draw();
        void MoveUp();
        void MoveDown();
        void setScore(int score);
        int getScore() const;
        int getX() const;
        int getY() const;
};