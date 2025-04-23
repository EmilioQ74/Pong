#include "Ball.h"

Ball::Ball()
{
   Initialize();
   dir = 0;
}
void Ball::Initialize()
{
    x = GAME_WIDTH/2 - BALL_WIDTH/2;
    y = GAME_HEIGHT/2 - BALL_HEIGHT/2;
    speed = 1.1;
    StartMove();
}
int Ball::BallOutside()
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
void Ball::StartMove()
{
    double angle;
    std::cout << dir << std::endl;
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

void Ball::SpeedUp()
{
    dirx *= speed;
    diry *= speed;
}

void Ball::WallCollision()
{
    
    if(y + BALL_HEIGHT >= GAME_HEIGHT || y <=0)
    {
        diry *= -1;
        update();
    }
}

void Ball::PaddleCollision(Player player)
{
    if(Overlap(player))
    {
        PaddlePhysics(player);
        dirx *= -1;
        SpeedUp();
        speed+=BALL_SPEED_INCREASE;
        update();
    }
}

bool Ball::Overlap(Player player)
{
    bool xOverlap = x >= player.getX() && x < player.getX() + PADDLE_WIDTH;
    bool yOverlap = y >= player.getY() && y < player.getY() + PADDLE_HEIGHT;
    return xOverlap && yOverlap;
}


void Ball::PaddlePhysics(Player player)
{
    double angle;
    double paddleTop = player.getY()+PADDLE_HEIGHT/4;
    double paddleBottom = player.getY()+3*PADDLE_HEIGHT/4;
    if(y > paddleTop)
    {
        if(dirx < 0)
        {
            angle = (rand() % 60+120) * M_PI / 180.0f; //120 to 180
            dirx =BALL_SPEED * cos(angle);
            diry =BALL_SPEED * sin(angle);
        }else
        {
            angle = (rand() % 60) * M_PI / 180.0f; //0 to 60
            dirx =BALL_SPEED * cos(angle);
            diry =BALL_SPEED * sin(angle);
        }
    }
    if (y < paddleBottom)
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

void Ball::update()
{
    x += dirx;
    y += diry;

}
void Ball::Draw()
{
    glColor3f(1,1,1);
    RoundBall();
    
}
void Ball::GameOver()
{
    dirx=0;
    diry=0;
}
void Ball::RoundBall()
{
    glBegin(GL_POLYGON);
    for (size_t i = 0; i < 360; i++)
    {
        double angle = i * M_PI / 180.0f;
        glVertex2f(x + BALL_RADIUS* cos(angle), y + BALL_RADIUS * sin(angle));
    }
    glEnd();
    
}
void Ball::SquareBall()
{
    glRectf(x - BALL_WIDTH/2,y - BALL_HEIGHT/2,x+BALL_WIDTH,y+BALL_HEIGHT); //center of the ball
}
