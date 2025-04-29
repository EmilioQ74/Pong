#include "Game.h"

Game::Game():player1(PADDLE_WIDTH_FROM_WALL, GAME_HEIGHT/2 - PADDLE_HEIGHT/2), player2(GAME_WIDTH - PADDLE_WIDTH_FROM_WALL*2, GAME_HEIGHT/2 - PADDLE_HEIGHT/2)
{
    ball = Ball();
    board = Board();
    menu = Menu();
    squareBall = false;
    MenuState = true;
    BallOnTheField = false;
    SettingState = false;
    DifficultyState = false;
    DifficultyMode = 0;
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

void Game::mouseClick(int button, int state, int x, int y)
{
    if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
    {
        // Menu
        if(menu.ClickButton(x,y,menu.start) && MenuState) 
        {
            MenuState = false;
            DifficultyState = true;
            return;
        }
        if(menu.ClickButton(x,y,menu.setting) && MenuState)
        {
            MenuState = false;
            SettingState = true;
            return;
        }
        if(menu.ClickButton(x,y,menu.quit) && MenuState)
        {
            exit(0);
            return;
        }

        if(menu.ClickButton(x,y,menu.SquareBall) && SettingState)
        {
            if(squareBall)
            {
                squareBall = false;
                return;
            }else{
                squareBall = true;
                return;
            }
        }
        if(menu.ClickButton(x,y,menu.quit) && SettingState)
        {
            SettingState = false;
            MenuState = true;
            return;
        }

        if(menu.ClickButton(x,y,menu.Easy) && DifficultyState)
        {
            Reset();
            DifficultyMode = 1;
            DifficultyState = false;
            return;
        }
        if(menu.ClickButton(x,y,menu.Medium) && DifficultyState)
        {
            Reset();
            DifficultyMode = 2;
            DifficultyState = false;
            return;
        }
        if(menu.ClickButton(x,y,menu.Hard) && DifficultyState)
        {
            Reset();
            DifficultyMode = 3;
            DifficultyState = false;
            return;
        }

    }
}

void Game::update()
{
    leftRightScore();
    KeyHandling();
    if (KeyStates['w']) player1.MoveUp();
    else if (KeyStates['s']) player1.MoveDown();
    if(!SinglePlayerMode)
    {
        if(SpecialKeyStates[GLUT_KEY_UP]) player2.MoveUp();
        else if(SpecialKeyStates[GLUT_KEY_DOWN]) player2.MoveDown();
    }else{
        player2.AiLogic(ball.getX(),ball.getY(),DifficultyMode);
    };
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
    if(MenuState) menu.DrawMenu();
    if(DifficultyState) menu.DrawDifficulty();
    if(SettingState) menu.DrawSetting();
    board.DrawDigit(player1.getScore(), PLAYER_1_SCORE_POSITION_X,SCORE_POSITION_Y);
    board.DrawDigit(player2.getScore(), PLAYER_2_SCORE_POSITION_X,SCORE_POSITION_Y);
    player1.Draw();
    player2.Draw();
    ball.Draw(squareBall);
}

void Game::Reset()
{
    player1 = Player(PADDLE_WIDTH_FROM_WALL, GAME_HEIGHT/2 - PADDLE_HEIGHT/2);
    player2 = Player(GAME_WIDTH - PADDLE_WIDTH_FROM_WALL*2, GAME_HEIGHT/2 - PADDLE_HEIGHT/2);
    player1.setScore(0);
    player2.setScore(0);
    ball.Initialize();
}