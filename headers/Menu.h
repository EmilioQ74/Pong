#pragma once
#include "GameConfig.h"

typedef struct
{
    float x,y;
    float width,height;
}Button;


class Menu{
    private:
    Button start;
    Button setting;
    Button quit;
    public:
        Menu();
        void DrawMenu();
        void DrawButton(Button button);
        void RenderText(float x, float y, void *font, const std::string &text);
};