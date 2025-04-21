#include <iostream>
#include <GL/freeglut.h>
#include <GL/gl.h>

#include "Player.h"
#define WIDTH 800
#define HEIGHT 600

Player player;
void init()
{
    glClearColor(0,0,0,0);
    
    glColor3f(0,0,0);

    glPointSize(1.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    //setting 0,0 top-left
    gluOrtho2D(0, (GLdouble)WIDTH,(GLdouble)HEIGHT,0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1,0,0);
    player.Draw();
    glutSwapBuffers();
}

int main(int argc, char** argv){
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(WIDTH,HEIGHT);
    //gets the user window width and height
    int userScreenWidth = glutGet(GLUT_SCREEN_WIDTH);
    int userScreenHeight = glutGet(GLUT_SCREEN_HEIGHT);
    glutInitWindowPosition((userScreenWidth-WIDTH)/2,(userScreenHeight-HEIGHT)/2);
    glutCreateWindow("PingPong");
    init();
    glutDisplayFunc(display);
    glutMainLoop();
}
