#pragma once
#include "GameConfig.h"
#include "Player.h"
#include "cmath"

class Ball
{
private:
    double x, y;
    double dirx, diry;
    double dir;
    double speed;
    void SpeedUp();
    bool Overlap(Player player);
    void PaddlePhysics(Player player);
    void SquareBall();
    void RoundBall();
public:
    Ball();
    void Initialize();
    int BallOutside();
    void StartMove();
    void WallCollision();
    void PaddleCollision(Player player);
    void update();
    void Draw();    

    void GameOver();
};
