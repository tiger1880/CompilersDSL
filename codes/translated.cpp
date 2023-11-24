#include <iostream>
#include <vector>
#include <GL/glut.h>
#include <string>
#include <cstdlib>
#include <cmath>
#include <deque>
#include "standard_lib.hpp"

int main(int argc, char **argv)
{
    for (int i = 0; i < 10; i++)
    {

        Point p = Point(0, 1, 1, 0, 0);
    }

    glutInit(&argc, argv);
    glutInitWindowSize(640, 480);
    glutInitWindowPosition(50, 50);
    glutCreateWindow("Figure");
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    init();
    glutMainLoop();

    return 0;
}
