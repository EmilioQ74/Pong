#pragma once
#include "GameConfig.h"
#include "Paddle.h"

class Player{
    private:
        double x,y;
        int score;
        Paddle paddle;
    public:
        Player();  // default constructor
        Player(double x,double y); // constructor
        void Draw(); // for drawing the paddle
        void MoveUp(); // for movingUp the paddle
        void MoveDown(); // for movingDown the paddle
        void setScore(int score); // for setting the score
        void AiLogic(double Ballx, double Bally,int mode); // for setting ai if single player
        int getScore() const; // for getting the score
        double getX() const; 
        double getY() const;
};