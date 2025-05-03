#include "Ball.h"

Ball::Ball() //constructor
{
    Initialize();
    dir = 0;
}
void Ball::Initialize() //initialize the ball
{
    x = GAME_WIDTH/2 - BALL_WIDTH/2;
    y = GAME_HEIGHT/2 - BALL_HEIGHT/2;
    speed = 1.5; //initial speed 
    StartMove();
}
int Ball::BallOutside() //check if the ball is outside the field
{
    if(x >= GAME_WIDTH) 
    {
        return 1;
    }
    if(x<=0)
    {
        return 2;
    }
    return 0;
}
void Ball::StartMove() //start moving the ball at random angle
{
    double angle;
    if(dir == 0)
    {
        angle = (rand() % 60 - 30) * M_PI / 180.0f; // -30° to +30°
        dir = 1;
    }
    else 
    {
        angle = (rand() % 60 + 150) * M_PI / 180.0f; //150° till 210°
        dir = 0;
    }
    dirx =BALL_SPEED * cos(angle);
    diry =BALL_SPEED * sin(angle);
}

void Ball::SpeedUp() //acceleration
{
    dirx *= speed;
    diry *= speed;
}

void Ball::WallCollision() //wall collision
{
    
    if(y + BALL_HEIGHT >= GAME_HEIGHT || y <=0) //if the ball hits the top or bottom wall
    {
        diry *= -1; //reverse the direction
        update(); //update the position
    }
}

bool Ball::PaddleCollision(Player player) //paddle collision
{
    if(Overlap(player)) //if the ball overlaps the paddle
    {
        PaddlePhysics(player); //paddle physics
        dirx *= -1; 
        SpeedUp();
        speed+=BALL_SPEED_INCREASE; //acceleration 
        update();
        return true;
    }
    return false;
}

bool Ball::Overlap(Player player) //check if the ball overlaps the paddle
{
    bool xOverlap = x >= player.getX() && x < player.getX() + PADDLE_WIDTH; //check if the ball overlaps the paddle by checking if the ball is inside the paddle
    bool yOverlap = y >= player.getY() && y < player.getY() + PADDLE_HEIGHT; //check if the ball overlaps the paddle by checking if the ball is inside the paddle
    return xOverlap && yOverlap; //if the ball x and y coordinates are inside the paddle return true
}


void Ball::PaddlePhysics(Player player) //making the ball bounce off the paddle if hits the paddle at the top or bottom
{
    double angle;
    double paddleTop = player.getY()+PADDLE_HEIGHT/4; //getting the top paddle
    double paddleBottom = player.getY()+3*PADDLE_HEIGHT/4; //getting the bottom paddle
    if(y > paddleTop) //if the ball hits the top paddle
    {
        if(dirx < 0) //if the ball is moving left
        {
            angle = (rand() % 60+120) * M_PI / 180.0f; //120 to 180
            dirx =BALL_SPEED * cos(angle);
            diry =BALL_SPEED * sin(angle);
        }else //if the ball is moving right
        {
            angle = (rand() % 60) * M_PI / 180.0f; //0 to 60
            dirx =BALL_SPEED * cos(angle);
            diry =BALL_SPEED * sin(angle);
        }
    }
    if (y < paddleBottom) //if the ball hits the bottom paddle
    {
        if(dirx < 0)
        {
            angle = (rand() % 60+180) * M_PI / 180.0f; //240 to 180
            dirx =BALL_SPEED * cos(angle);
            diry =BALL_SPEED * sin(angle);
        }else
        {
            angle = (rand() % 60 + 300) * M_PI / 180.0f; //120 to 180
            dirx =BALL_SPEED * cos(angle);
            diry =BALL_SPEED * sin(angle);
        }
    }
    
}

void Ball::update() //update the position
{
    x += dirx;
    y += diry;

}
void Ball::Draw(bool squareBall) //draw the ball
{
    ThemeManager::getTheme().ball.apply();
    if(squareBall) SquareBall();
    else RoundBall();
    
}
void Ball::GameOver() //Stops the ball
{
    dirx=0;
    diry=0;
}
double Ball::getX() const
{
    return x;
}
double Ball::getY() const
{
    return y;
}
void Ball::RoundBall() //Draws the ball as a circle
{
    glBegin(GL_POLYGON);
    for (size_t i = 0; i < 360; i++)
    {
        double angle = i * M_PI / 180.0f;
        glVertex2f(x + BALL_RADIUS* cos(angle), y + BALL_RADIUS * sin(angle));
    }
    glEnd();
    
}
void Ball::SquareBall() //Draws the ball as a square
{
    glRectf(x - BALL_WIDTH/2,y - BALL_HEIGHT/2,x+BALL_WIDTH,y+BALL_HEIGHT); //center of the ball
}
