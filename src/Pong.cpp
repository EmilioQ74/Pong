#include "Pong.h"

Pong::Pong(int x, int y)
{
    this->x = x;
    this->y = y;
    size_x = 5;
    size_y = 10;
}

// draws rectangle of the pong
void Pong::Draw()
{
    glColor3f(0,0,0);
    glRectf(x,y,x+size_x,y+size_y);
}