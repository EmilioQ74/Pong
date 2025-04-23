#include "Player.h"

Player::Player(): paddle(0, 0)
{
    x = 0;
    y = 0;
    score = 0;
}

Player::Player(int x, int y) : paddle(x, y)
{
    this->x = x;
    this->y = y;
    score = 0;
}

void Player::Draw()
{
    paddle.Draw();
}

void Player::MoveUp()
{
    if(y - PADDLE_SPEED >= 0) y -= PADDLE_SPEED; //prevents paddle from going out of the screen
    paddle.setY(y);
}

void Player::MoveDown()
{
    if(y +PADDLE_HEIGHT+ PADDLE_SPEED <= GAME_HEIGHT) y += PADDLE_SPEED; //prevents paddle from going out of the screen
    paddle.setY(y);
}

void Player::setScore(int score)
{
    this->score = score;
}

int Player::getScore() const
{
    return score;
}

int Player::getX() const
{
    return x;
}

int Player::getY() const
{
    return y;
}
