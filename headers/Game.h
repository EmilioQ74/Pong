#pragma once 
#include "Player.h"
#include "Board.h"
#include "Ball.h"
#include "Menu.h"

enum MenuState 
{
    PLAY,
    MENU,
    SETTING,
    DIFFICULTY,
    PAUSE,
    MODE,
    WINNER,
};



class Game{
    private:
        Player player1, player2;
        Ball ball;
        Board board;
        Menu menu;
        MenuState CurrentMenuState;
        bool Pause;
        bool squareBall;
        int DifficultyMode;
        bool SinglePlayerMode;
        std::string Winner;
        bool SoundOn;
        bool MusicOn;
        bool hit;
        static const int KeyCount = 256;
        bool KeyStates[KeyCount] = {false};
        bool SpecialKeyStates[KeyCount] = {false};
        void MenuDraw();
        void gameInputs();
        void initialize();
        void leftRightScore();
        void SoundHandling();
        void Reset();
        void isGameOver();

    public:
        Game();
        void update();
        void Draw();
        void keyDown(unsigned char key, int x, int y);
        void keyUp(unsigned char key, int x, int y);
        void specialKeyDown(int key, int x, int y);
        void specialKeyUp(int key, int x, int y);
        void mouseClick(int button, int state, int x, int y);
};