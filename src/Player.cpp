#include "Player.h"

Player::Player(): paddle(0, 0) //default constructor
{
    x = 0;
    y = 0;
    score = 0;
}

Player::Player(double x, double y) : paddle(x, y) //constructor
{
    this->x = x;
    this->y = y;
    score = 0;
}

void Player::Draw() //draws the paddle need it for Game.cpp
{
    paddle.Draw();
}

void Player::MoveUp() //moves the paddle up
{
    if(y - paddle.getSpeed() >= 0) y -= paddle.getSpeed(); //prevents paddle from going out of the screen
    paddle.setY(y);
}

void Player::MoveDown() //moves the paddle down
{
    if(y +PADDLE_HEIGHT+ paddle.getSpeed() <= GAME_HEIGHT) y += paddle.getSpeed(); //prevents paddle from going out of the screen
    paddle.setY(y);
}

void Player::setScore(int score) //sets the score
{
    this->score = score;
}

void Player::AiLogic(double Ballx, double Bally,int mode) //ai logic by mode we set different difficulty
{
    double wrongInputs; //needs to make ai more random and beateable
    switch (mode) {
        case 1:
            wrongInputs = (rand() % 61) - 30; //-30 to 30
            paddle.setSpeed(3);
            if (Ballx >= GAME_WIDTH / 2) {
                paddle.setSpeed(3 * 1.5); //acceleration only when ball has pass the middle
            }
            break;
        case 2:
            wrongInputs = (rand() % 41) - 20; //-20 to 20
            paddle.setSpeed(3);
            if (Ballx >= GAME_WIDTH / 2) {
                paddle.setSpeed(4 * 1.5);
            }
            break;
        case 3:
            wrongInputs = (rand() % 21) - 10; //-10 to 10
            paddle.setSpeed(4);
            if (Ballx >= GAME_WIDTH / 2) {
                paddle.setSpeed(5 * 1.5);
            }
            break;
        case 0:
            wrongInputs = 0; //no wrong inputs for unbeateable
            paddle.setSpeed(PADDLE_SPEED);
            break;
    }
    if(Ballx < GAME_WIDTH / 2 && mode != 0) //makes the ai to go to the center when tha ball is on the other field
    {
        if(y + PADDLE_HEIGHT/2 <= GAME_HEIGHT / 2 + PADDLE_HEIGHT && y - PADDLE_HEIGHT/2 > GAME_HEIGHT / 2 - PADDLE_HEIGHT) //if the paddle is in the middle so it does not go up and down
        {
            return;
        }
        if(y > GAME_HEIGHT / 2) 
        {
            MoveUp();
        }else 
        {
            MoveDown();
        }
        
    }else{ //Here is the ai logic
        if(y + PADDLE_HEIGHT/2>= Bally+wrongInputs) //if paddle y is above the ball it moves up
        {
            MoveUp();
        }
        if(y + PADDLE_HEIGHT/2 <= Bally + wrongInputs) //if paddle y is below the ball it moves down
        {
            MoveDown();
        }
    }
    
}

int Player::getScore() const
{
    return score;
}

double Player::getX() const
{
    return x;
}

double Player::getY() const
{
    return y;
}
