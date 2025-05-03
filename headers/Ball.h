#pragma once
#include "GameConfig.h"
#include "Player.h"
#include "Colors.h"
#include "cmath"

class Ball
{
private:
    double x, y;
    double dirx, diry;
    double dir;
    double speed;
    void SpeedUp(); //acceleration
    bool Overlap(Player player); //check if the ball overlaps the paddle
    void PaddlePhysics(Player player); //paddle physics
    void SquareBall(); //draws the ball as a square
    void RoundBall(); //draws the ball as a circle
public:
    Ball();
    void Initialize();//initialize the ball
    int BallOutside(); //check if the ball is outside the field for scoring
    void StartMove(); //start moving the ball
    void WallCollision(); //wall collision
    bool PaddleCollision(Player player); //paddle collision
    void update(); //update the ball
    void Draw(bool squareBall);     //draw the ball

    void GameOver(); //game over

    double getX() const;
    double getY() const;
};
