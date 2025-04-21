#include "Player.h"

Player::Player()
{
    this->pong = pong;
    score = 0;
}

void Player::setScore(int score)
{
    this->score = score;
}

int Player::getScore() const
{
    return score;
}
