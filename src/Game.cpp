#include "Game.h"

Game::Game():player1(PADDLE_WIDTH_FROM_WALL, GAME_HEIGHT/2 - PADDLE_HEIGHT/2), player2(GAME_WIDTH - PADDLE_WIDTH_FROM_WALL*2, GAME_HEIGHT/2 - PADDLE_HEIGHT/2)
{
    ball = Ball();
    board = Board();
    BallOnTheField = false;

}

void Game::initialize()
{
    
}

void Game::leftRightScore()
{
    if(ball.BallOutside() == 1)
    {
        player1.setScore(player1.getScore() + 1);
        ball.Initialize();
    }
    if(ball.BallOutside() == 2)
    {
        player2.setScore(player2.getScore() + 1);
        ball.Initialize();
    }
}
void Game::keyDown(unsigned char key, int x, int y)
{
    KeyStates[key] = true;
}
void Game::keyUp(unsigned char key, int x, int y)
{
    KeyStates[key] = false;
}

void Game::specialKeyDown(int key, int x, int y)
{
    SpecialKeyStates[key] = true;
}
void Game::specialKeyUp(int key, int x, int y)
{
    SpecialKeyStates[key] = false;
}

void Game::update()
{
    leftRightScore();
    KeyHandling();
    if (KeyStates['w']) player1.MoveUp();
    else if (KeyStates['s']) player1.MoveDown();
    if(SpecialKeyStates[GLUT_KEY_UP]) player2.MoveUp();
    else if(SpecialKeyStates[GLUT_KEY_DOWN]) player2.MoveDown();
    ball.update();
    ball.WallCollision();
    ball.PaddleCollision(player1);
    ball.PaddleCollision(player2);
    
}
void Game::KeyHandling()
{
    if(KeyStates['q']) exit(0);
    if (KeyStates['r'])
    {
        ball.GameOver();
    }
    
}
void Game::Draw()
{
    board.Draw();
    board.DrawDigit(player1.getScore(), PLAYER_1_SCORE_POSITION_X,SCORE_POSITION_Y);
    board.DrawDigit(player2.getScore(), PLAYER_2_SCORE_POSITION_X,SCORE_POSITION_Y);
    player1.Draw();
    player2.Draw();
    ball.Draw();
}

void Game::Reset()
{
    player1.setScore(0);
    player2.setScore(0);
}