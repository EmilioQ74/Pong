#include <iostream>
#include "GameConfig.h"
#include "Game.h"


static Game game;

void keyDown(unsigned char key, int x, int y)
{
    game.keyDown(key,x,y);
}
void keyUp(unsigned char key, int x, int y)
{
    game.keyUp(key,x,y);
}

void specialKeyDown(int key, int x, int y)
{
    game.specialKeyDown(key,x,y);
}
void specialKeyUp(int key, int x, int y)
{
    game.specialKeyUp(key,x,y);
}
void FPS(int value)
{
    game.update();
    glutPostRedisplay();
    glutTimerFunc(1000/60, FPS, 0);
}

void init()
{
    glClearColor(0,0,0,0);
    
    glColor3f(0,0,0);

    glPointSize(1.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    //setting 0,0 top-left
    gluOrtho2D(0, (GLdouble)GAME_WIDTH,(GLdouble)GAME_HEIGHT,0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}
void reshape(int w, int h)
{
    glViewport(0,0,w,h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0, (GLdouble)w,(GLdouble)h,0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}
void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1,0,0);
    game.Draw();
    glutSwapBuffers();
}

int main(int argc, char** argv){
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(GAME_WIDTH,GAME_HEIGHT);
    //gets the user window width and height
    int userScreenWidth = glutGet(GLUT_SCREEN_WIDTH);
    int userScreenHeight = glutGet(GLUT_SCREEN_HEIGHT);
    glutInitWindowPosition((userScreenWidth-GAME_WIDTH)/2,(userScreenHeight-GAME_HEIGHT)/2);
    glutCreateWindow("PingPong");
    init();
    glutDisplayFunc(display);
    //keyboard
    glutKeyboardFunc(keyDown);
    glutKeyboardUpFunc(keyUp);
    glutSpecialFunc(specialKeyDown);
    glutSpecialUpFunc(specialKeyUp);
    //timer
    glutTimerFunc(0, FPS, 0);
    //reshape
    glutReshapeFunc(reshape);
    glutMainLoop();
}
