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
    Pause = false;
    GameOver = true;
    Theme CurrentTheme = ThemeManager::getTheme();
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
        // 1st menu
        if(menu.ClickButton(x,y,menu.topButton) && MenuState) //start
        {
            MenuState = false;
            DifficultyState = true;
            return;
        }
        if(menu.ClickButton(x,y,menu.middleButton) && MenuState) //setting
        {
            MenuState = false;
            SettingState = true;
            return;
        }
        if(menu.ClickButton(x,y,menu.bottomButton) && MenuState) //quit
        {
            exit(0);
            return;
        }
        //end 1st menu
        //setting menu
        if(menu.ClickButton(x,y,menu.topButton) && SettingState) //theme
        {
            ThemeManager::setTheme(ThemeManager::getTheme().isClassic() ? ModernTheme : ClassicTheme);
            glutPostRedisplay();
            return;
        }
        if(menu.ClickButton(x,y,menu.middleButton) && SettingState) //ball
        {
            squareBall = !squareBall;
            glutPostRedisplay();
            return;
        }
        if(menu.ClickButton(x,y,menu.bottomButton) && SettingState) //back
        {
            SettingState = false;
            MenuState = true;
            return;
        }
        //end setting
        //difficulty
        if(menu.ClickButton(x,y,menu.topButton) && DifficultyState) //easy
        {
            Reset();
            DifficultyMode = 1;
            DifficultyState = false;
            return;
        }
        if(menu.ClickButton(x,y,menu.middleButton) && DifficultyState) //medium
        {
            Reset();
            DifficultyMode = 2;
            DifficultyState = false;
            return;
        }
        if(menu.ClickButton(x,y,menu.bottomButton) && DifficultyState) //hard
        {
            Reset();
            DifficultyMode = 3;
            DifficultyState = false;
            return;
        }
        //end difficulty
        //pause
        if(menu.ClickButton(x,y,menu.topButton) && Pause ) //continue
        {
            Pause = false;
            return;
        }
        if(menu.ClickButton(x,y,menu.middleButton) && Pause ) //setting
        {
            Pause = false;
            SettingState = true;
            return;
        }
        if(menu.ClickButton(x,y,menu.bottomButton) && Pause )  //back
        {
            Pause = false;
            return;
        }

    }
}

void Game::update()
{
    leftRightScore();
    gameInputs();
    if(!GameOver || !Pause)
    {
        ball.update();
    }
    ball.WallCollision();
    ball.PaddleCollision(player1);
    ball.PaddleCollision(player2);
}

void Game::gameInputs()
{
    if(KeyStates['p'] || KeyStates['P'] || KeyStates[27] && (!MenuState && !DifficultyState && !SettingState)) 
    {
        Pause = !Pause;
    }
    KeyStates['p'] = false;
    KeyStates['P'] = false;
    KeyStates[27] = false;
    if(!GameOver || !Pause)
    {
        if (KeyStates['w'] || KeyStates['W']) player1.MoveUp();
    else if (KeyStates['s'] || KeyStates['S']) player1.MoveDown();
    if(!SinglePlayerMode)
    {
        if(SpecialKeyStates[GLUT_KEY_UP]) player2.MoveUp();
        else if(SpecialKeyStates[GLUT_KEY_DOWN]) player2.MoveDown();
    }else{
        player2.AiLogic(ball.getX(),ball.getY(),DifficultyMode);
    };
    }
}
void Game::Draw()
{
    board.Draw();
    if(MenuState) menu.DrawMenu();
    if(DifficultyState) menu.DrawDifficulty();
    if(SettingState) menu.DrawSetting();
    if(Pause) menu.DrawPause();
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