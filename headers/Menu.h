#pragma once
#include "GameConfig.h"

typedef struct
{
    float x,y;
    float width,height;
}Button;


class Menu{
    private:
   
    public:
        Button start;
        Button setting;
        Button quit;
        Button Easy;
        Button Medium;
        Button Hard;
        Button SquareBall;
        Menu();
        bool ClickButton(int x, int y, Button button);
        void DrawMenu();
        void DrawDifficulty();
        void DrawSetting();
        void DrawButton(Button button);
        void RenderText(float x, float y, void *font, const std::string &text);
};