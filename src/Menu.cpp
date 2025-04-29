#include "Menu.h"

Menu::Menu()
{
    start = {GAME_WIDTH/2-50,GAME_HEIGHT/4,100,50};
    setting = {GAME_WIDTH/2-50,GAME_HEIGHT/2,100,50};
    quit = {GAME_WIDTH/2-50,GAME_HEIGHT*3/4,100,50};

    Easy = {GAME_WIDTH/2-50,GAME_HEIGHT/4,100,50};
    Medium = {GAME_WIDTH/2-50,GAME_HEIGHT/2,100,50};
    Hard = {GAME_WIDTH/2-50,GAME_HEIGHT*3/4,100,50};

    SquareBall = {GAME_WIDTH/2-100,GAME_HEIGHT/2,200,50};

}

bool Menu::ClickButton(int x, int y , Button button)
{
    if(x >= button.x && x <= button.x + button.width && y >= button.y && y <= button.y + button.height)
        return true;
    return false;
}

void Menu::DrawMenu()
{
   
    DrawButton(start);
    glColor3f(1,0,0);
    RenderText(start.x+30,start.y+30,GLUT_BITMAP_HELVETICA_18,"START");
    glColor3f(1,1,0);
    DrawButton(setting);
    glColor3f(1,1,1);
    RenderText(setting.x+30,setting.y+30,GLUT_BITMAP_HELVETICA_18,"SETTING");
    glColor3f(0,0,1);
    DrawButton(quit);
    glColor3f(1,1,1);
    RenderText(quit.x+30,quit.y+30,GLUT_BITMAP_HELVETICA_18,"QUIT");
}

void Menu::DrawDifficulty()
{
    DrawButton(Easy);
    glColor3f(1,0,0);
    RenderText(Easy.x+30,Easy.y+30,GLUT_BITMAP_HELVETICA_18,"EASY");
    glColor3f(1,1,0);
    DrawButton(Medium);
    glColor3f(1,1,1);
    RenderText(Medium.x+30,Medium.y+30,GLUT_BITMAP_HELVETICA_18,"MEDIUM");
    glColor3f(0,0,1);
    DrawButton(Hard);
    glColor3f(1,1,1);
    RenderText(Hard.x+30,Hard.y+30,GLUT_BITMAP_HELVETICA_18,"HARD");
}

void Menu::DrawSetting()
{
    DrawButton(SquareBall);
    glColor3f(1,0,0);
    RenderText(SquareBall.x,SquareBall.y,GLUT_BITMAP_HELVETICA_18,"CHECK FOR SQUARE");
    DrawButton(quit);
    RenderText(quit.x+30,quit.y+30,GLUT_BITMAP_HELVETICA_18,"QUIT");
}

void Menu::DrawButton(Button button)
{
    glColor3f(0,1,0);
    glRectf(button.x,button.y,button.x+button.width,button.y+button.height);
}

void Menu::RenderText(float x, float y, void *font, const std::string &text)
{
    glRasterPos2f(x,y);
    for(char c:text)
        glutBitmapCharacter(font,c);
}
