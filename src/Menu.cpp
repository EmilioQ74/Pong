#include "Menu.h"

Menu::Menu()
{
    start = {GAME_WIDTH/2-50,GAME_HEIGHT/4,100,50};
}


void Menu::DrawMenu()
{
   
    DrawButton(start);
    glColor3f(1,0,0);
    RenderText(start.x+30,start.y+30,GLUT_BITMAP_HELVETICA_18,"START");

    
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
