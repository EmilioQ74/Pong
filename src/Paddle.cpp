#include "Paddle.h"

Paddle::Paddle(int x, int y)
{
    this->x = x;
    this->y = y;
    width = PADDLE_WIDTH;
    height = PADDLE_HEIGHT;
}

void Paddle::setY(int y)
{
    this->y = y;
}

// draws rectangle of the Paddle
void Paddle::Draw()
{
    glColor3f(1,1,1);
    glRectf(x,y,x+width,y+height);
}

