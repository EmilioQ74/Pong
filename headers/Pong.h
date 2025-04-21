#pragma once
#include <GL/freeglut.h>
#include <GL/gl.h>

class Pong{
    private:
        int x,y,size_x,size_y;
    public:
        Pong(int x,int y);
        void Draw();
}