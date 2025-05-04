#include "Game.h"
#include "Music.h"

Game::Game():player1(PADDLE_WIDTH_FROM_WALL, GAME_HEIGHT/2 - PADDLE_HEIGHT/2), player2(GAME_WIDTH - PADDLE_WIDTH_FROM_WALL*2, GAME_HEIGHT/2 - PADDLE_HEIGHT/2)
{
    ball = Ball();
    board = Board();
    menu = Menu();
    CurrentMenuState = MENU;
    squareBall = false;
    DifficultyMode = 0;
    Pause = false;
    SinglePlayerMode = true;
    SoundOn = true;
    hit = false;
    Winner = "";
    MusicOn = true;
    PlaySound(SOUNDTRACK, NULL, SND_ASYNC | SND_LOOP);
}

void Game::initialize()
{
    CurrentMenuState = MENU;
    Pause = false;
    Winner = "";
    hit = false;
}
//left and right score
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
//mouse click events
void Game::mouseClick(int button, int state, int x, int y)
{
    if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
    {
        if(menu.ClickButton(x,y,menu.MuteButton)) //mute
        {
            SoundOn = !SoundOn;
            return;
        } 
        switch (CurrentMenuState)
        {
        case MENU:
            if(menu.ClickButton(x,y,menu.topButton)) //start
            {
                CurrentMenuState=MODE;
                return;
            }
            if(menu.ClickButton(x,y,menu.middleButton)) //setting
            {
                CurrentMenuState=SETTING;
                return;
            }
            if(menu.ClickButton(x,y,menu.bottomButton)) //quit
            {
                exit(0);
                return;
            }
            break;
        case MODE:
            if(menu.ClickButton(x,y,menu.topButton)) //single
            {
                SinglePlayerMode = true;
                CurrentMenuState = DIFFICULTY;
                return;
            }
            if(menu.ClickButton(x,y,menu.middleButton)) //multi
            {
                Reset();
                SinglePlayerMode = false;
                CurrentMenuState = PLAY;
                return;
            }
            if(menu.ClickButton(x,y,menu.bottomButton)) //back
            {
                CurrentMenuState = MENU;
                return;
            }
            break;
        case SETTING:
            if(menu.ClickButton(x,y,menu.topButton)) //theme
            {
                ThemeManager::setTheme(ThemeManager::getTheme().isClassic() ? ModernTheme : ClassicTheme);
                glutPostRedisplay();
                return;
            }
            if(menu.ClickButton(x,y,menu.middleButton)) //ball
            {
                squareBall = !squareBall;
                glutPostRedisplay();
                return;
            }
            if(menu.ClickButton(x,y,menu.bottomButton)) //back
            {
                if(Pause)
                {
                    CurrentMenuState = PAUSE;
                    return;
                }
                CurrentMenuState = MENU;
                return;
            }
            break;
        case PAUSE:
            if(menu.ClickButton(x,y,menu.topButton)) //continue
            {
                Pause = false;
                CurrentMenuState = PLAY;
                return;
            }
            if(menu.ClickButton(x,y,menu.middleButton)) //setting
            {
                CurrentMenuState = SETTING;
                return;
            }
            if(menu.ClickButton(x,y,menu.bottomButton)) //back
            {
                CurrentMenuState = MENU;
                return;
            }
            break;
        case WINNER:
            if(menu.ClickButton(x,y,menu.winnerButton))
            {
                CurrentMenuState = MENU;
                initialize();
                DifficultyMode = 0;
                SinglePlayerMode = true;
                glutPostRedisplay();
                return;
            }
            break;
        case DIFFICULTY:
            if(menu.ClickButton(x,y,menu.topButton)) //easy
            {
                Reset();
                DifficultyMode = 1;
                CurrentMenuState = PLAY;
                return;
            }
            if(menu.ClickButton(x,y,menu.middleButton)) //medium
            {
                Reset();
                DifficultyMode = 2;
                CurrentMenuState = PLAY;
                return;
            }
            if(menu.ClickButton(x,y,menu.bottomButton)) //hard
            {
                Reset();
                DifficultyMode = 3;
                CurrentMenuState = PLAY;
                return;
            }
        case PLAY:
            break;
        default:
            break;
        }
    }
}
//GameLoop 
void Game::update()
{
    leftRightScore();
    gameInputs();
    SoundHandling();
    if(!(Pause || CurrentMenuState == WINNER))
    {
        ball.update();
    }
    ball.WallCollision();
    if(ball.PaddleCollision(player1) || ball.PaddleCollision(player2))hit = true;
}
//MENU DRAW 
void Game::MenuDraw()
{
    if(SoundOn) menu.DrawMute("ON");
    else menu.DrawMute("OFF");
    switch (CurrentMenuState)
    {
    case MENU:
        menu.DrawMenu();
        break;
    case MODE:
        menu.DrawMode();
        break;
    case SETTING:
        menu.DrawSetting();
        break;
    case DIFFICULTY:
        menu.DrawDifficulty();
        break;
    case PAUSE:
        menu.DrawPause();
        break;
    case WINNER:
        menu.DrawWinner(Winner);
        break;
    case PLAY:
        break;
    default:
        break;
    }
}
//GAME INPUTS by keyboard
void Game::gameInputs()
{
    if(KeyStates['p'] || KeyStates['P'] || KeyStates[27] && (CurrentMenuState == PLAY || CurrentMenuState == PAUSE)) 
    {
        Pause = !Pause;
        if(Pause) CurrentMenuState = PAUSE;
        else CurrentMenuState = PLAY;
        KeyStates['p'] = false;
        KeyStates['P'] = false;
        KeyStates[27] = false;
    }
    
    if(!Pause)
    {
        if (KeyStates['w'] || KeyStates['W']) player1.MoveUp();
    else if (KeyStates['s'] || KeyStates['S']) player1.MoveDown();
    if(!SinglePlayerMode)
    {
        if(SpecialKeyStates[GLUT_KEY_UP]) player2.MoveUp();
        else if(SpecialKeyStates[GLUT_KEY_DOWN]) player2.MoveDown();
    }else{
        player2.AiLogic(ball.getX(),ball.getY(),DifficultyMode);
        }
    }
    if(KeyStates['m'] || KeyStates['M'])
    {
        SoundOn = !SoundOn;
        KeyStates['m'] = false;
        KeyStates['M'] = false;
    }
}

//GAME DRAW
void Game::Draw()
{
    board.Draw();
    MenuDraw();
    if(CurrentMenuState == PLAY)
    {
        board.DrawDigit(player1.getScore(), PLAYER_1_SCORE_POSITION_X,SCORE_POSITION_Y);
        board.DrawDigit(player2.getScore(), PLAYER_2_SCORE_POSITION_X,SCORE_POSITION_Y);
    }
    player1.Draw();
    player2.Draw();
    ball.Draw(squareBall);
    isGameOver();
}
//SOUND HANDLING
void Game::SoundHandling()
{
    if(!SoundOn) 
    {
        PlaySound(NULL, NULL, 0);
        MusicOn = false;
    }
    if(SoundOn && CurrentMenuState != PLAY && !MusicOn) 
    {
        PlaySound(SOUNDTRACK, NULL, SND_ASYNC | SND_LOOP);
        MusicOn = true;
        }
    if(SoundOn && CurrentMenuState == PLAY && hit)
    {
        int randNum = rand() % 2;
        if(randNum == 0) PlaySound(HIT1, NULL, SND_ASYNC);
        else PlaySound(HIT2, NULL, SND_ASYNC );
        hit = false;
    }
}
//RESET
void Game::Reset()
{
    player1 = Player(PADDLE_WIDTH_FROM_WALL, GAME_HEIGHT/2 - PADDLE_HEIGHT/2);
    player2 = Player(GAME_WIDTH - PADDLE_WIDTH_FROM_WALL*2, GAME_HEIGHT/2 - PADDLE_HEIGHT/2);
    player1.setScore(0);
    player2.setScore(0);
    ball.Initialize();
}
//GAME OVER CHECK
void Game::isGameOver()
{
    if(CurrentMenuState == PLAY)
    {
        if(player1.getScore() == MAX_SCORE)
        {
        CurrentMenuState = WINNER;
        Winner = "Player 1";
        }
    if(player2.getScore() == MAX_SCORE)
        {
        CurrentMenuState = WINNER;
        if(SinglePlayerMode) Winner = "Computer";
        else Winner = "Player 2";
        }
    }
    
}