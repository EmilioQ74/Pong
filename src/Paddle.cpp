#include "Paddle.h"

Paddle::Paddle(double x, double y)  // constructor sets also the width and height
{
    this->x = x;
    this->y = y;
    width = PADDLE_WIDTH;
    height = PADDLE_HEIGHT;
}

void Paddle::setY(double y) 
{
    this->y = y;
}

// draws rectangle of the Paddle
void Paddle::Draw()
{
    ThemeManager::getTheme().paddle.apply();
    glRectf(x,y,x+width,y+height);
}

void Paddle::setSpeed(double speed)
{
    this->speed = speed;
}

double Paddle::getSpeed()
{
    return speed;
}
