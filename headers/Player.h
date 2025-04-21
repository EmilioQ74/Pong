#pragma once
#include <GL/freeglut.h>
#include <GL/gl.h>

class Player{
    private:
        int score;
    public:
        Player();
        void setScore(int score);
        int getScore() const;
};