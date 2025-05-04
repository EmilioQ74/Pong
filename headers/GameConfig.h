
// Include necessary headers
#include "GL/freeglut.h"
#include "GL/gl.h"
#include "GL/glu.h"

// Standard libraries
#include <iostream>

//FOR MCVS
#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

#include <cmath>

//Game
#define GAME_WIDTH 800
#define GAME_HEIGHT 600

//Paddle
#define PADDLE_WIDTH 20
#define PADDLE_HEIGHT 100
#define PADDLE_WIDTH_FROM_WALL 20

#define PADDLE_SPEED 10

//Ball 
#define BALL_HEIGHT 12
#define BALL_WIDTH 12

#define BALL_RADIUS 8  //need for creating the circle

#define BALL_SPEED 6
#define BALL_SPEED_INCREASE 0.1

// Digits font-size
#define DIGIT_WIDTH 60
#define DIGIT_HEIGHT 80

#define SEGMENT_WIDTH 8
#define SEGMENT_HEIGHT 8


//Score
#define PLAYER_1_SCORE_POSITION_X (GAME_WIDTH/4 - DIGIT_WIDTH/2)
#define PLAYER_2_SCORE_POSITION_X (3*GAME_WIDTH/4 - DIGIT_WIDTH/2)
#define SCORE_POSITION_Y 50
#define MAX_SCORE 5