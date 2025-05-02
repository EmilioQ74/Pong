#include "Menu.h"

Menu::Menu()
{
    topButton = {GAME_WIDTH/2-50,GAME_HEIGHT/4,100,50};
    middleButton = {GAME_WIDTH/2-50,GAME_HEIGHT/2,100,50};
    bottomButton = {GAME_WIDTH/2-50,GAME_HEIGHT*3/4,100,50};
}

bool Menu::ClickButton(int x, int y , Button button)
{
    if(x >= button.x && x <= button.x + button.width && y >= button.y && y <= button.y + button.height)
        return true;
    return false;
}

void Menu::DrawMenu()
{
    DrawButton(topButton);
    RenderText(topButton.x+20,topButton.y+30,GLUT_BITMAP_HELVETICA_18,"START");
    DrawButton(middleButton);
    RenderText(middleButton.x+10,middleButton.y+30,GLUT_BITMAP_HELVETICA_18,"SETTING");
    DrawButton(bottomButton);
    RenderText(bottomButton.x+25,bottomButton.y+30,GLUT_BITMAP_HELVETICA_18,"QUIT");
}

void Menu::DrawDifficulty()
{
    DrawButton(topButton);
    RenderText(topButton.x+25,topButton.y+30,GLUT_BITMAP_HELVETICA_18,"EASY");
    DrawButton(middleButton);
    RenderText(middleButton.x+15,middleButton.y+30,GLUT_BITMAP_HELVETICA_18,"MEDIUM");
    DrawButton(bottomButton);
    RenderText(bottomButton.x+25,bottomButton.y+30,GLUT_BITMAP_HELVETICA_18,"HARD");
}

void Menu::DrawSetting()
{
    DrawButton(topButton);
    RenderText(topButton.x+20,topButton.y+30,GLUT_BITMAP_HELVETICA_18,"THEME");
    DrawButton(middleButton);
    RenderText(middleButton.x+20,middleButton.y+30,GLUT_BITMAP_HELVETICA_18,"BALL");
    DrawButton(bottomButton);
    RenderText(bottomButton.x+25,bottomButton.y+30,GLUT_BITMAP_HELVETICA_18,"BACK");
}
void Menu::DrawPause()
{
    DrawButton(topButton);
    RenderText(topButton.x+20,topButton.y+30,GLUT_BITMAP_HELVETICA_18,"CONTINUE");
    DrawButton(middleButton);
    RenderText(middleButton.x+20,middleButton.y+30,GLUT_BITMAP_HELVETICA_18,"SETTING");
    DrawButton(bottomButton);
    RenderText(bottomButton.x+25,bottomButton.y+30,GLUT_BITMAP_HELVETICA_18,"BACK");
}
void Menu::DrawButton(Button button)
{
    ThemeManager::getTheme().button.apply();
    glRectf(button.x,button.y,button.x+button.width,button.y+button.height);
}

void Menu::RenderText(float x, float y, void *font, const std::string &text)
{
    ThemeManager::getTheme().text.apply();
    glRasterPos2f(x,y);
    for(char c:text)
        glutBitmapCharacter(font,c);
}
