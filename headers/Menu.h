#pragma once
#include "GameConfig.h"
#include "Colors.h"


typedef struct
{
    float x,y;
    float width,height;
}Button;


class Menu{
    private:
   
    public:
        Button topButton;
        Button middleButton;
        Button bottomButton;
        Button winnerButton;
        Button MuteButton;
        Menu();
        bool ClickButton(int x, int y, Button button);
        void DrawMenu();
        void DrawMode();
        void DrawDifficulty();
        void DrawSetting();
        void DrawPause();
        void DrawMute(std::string onOff);
        void DrawWinner(std::string winner);
        void DrawButton(Button button);
        void RenderText(float x, float y, void *font, const std::string &text);
};