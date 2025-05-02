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
        Menu();
        bool ClickButton(int x, int y, Button button);
        void DrawMenu();
        void DrawDifficulty();
        void DrawSetting();
        void DrawPause();
        void DrawButton(Button button);
        void RenderText(float x, float y, void *font, const std::string &text);
};