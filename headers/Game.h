#pragma once 
#include "Player.h"
#include "Board.h"
#include "Ball.h"
#include "Menu.h"

class Game{
    private:
        Player player1, player2;
        Ball ball;
        Board board;
        Menu menu;
        bool squareBall;
        bool MenuState;
        bool DifficultyState;
        int DifficultyMode;
        bool SettingState;
        bool BallOnTheField;
        bool SinglePlayerMode = true;
        static const int KeyCount = 256;
        bool KeyStates[KeyCount] = {false};
        bool SpecialKeyStates[KeyCount] = {false};
        void KeyHandling();
    public:
        Game();
        void initialize();
        void leftRightScore();
        void keyDown(unsigned char key, int x, int y);
        void keyUp(unsigned char key, int x, int y);
        void specialKeyDown(int key, int x, int y);
        void specialKeyUp(int key, int x, int y);
        void mouseClick(int button, int state, int x, int y);
        void update();
        void Draw();
        void Reset();
};