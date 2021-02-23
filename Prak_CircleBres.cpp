/*
 * GLUT Shapes Demo
 *
 * Written by Nigel Stewart November 2003
 *
 * This program is test harness for the sphere, cone
 * and torus shapes in GLUT.
 *
 * Spinning wireframe and smooth shaded shapes are
 * displayed until the ESC or q key is pressed.  The
 * number of geometry stacks and slices can be adjusted
 * using the + and - keys.
 */
#include<windows.h>
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
#include<stdio.h>
#include <stdlib.h>

void circleBres(int xc, int yc, int r)
{
    int x = 0, y = r;
    int d = 3 - 2 * r;
    void circlePlotPoints (int, int, int, int);
    while (y >= x)
    {
        // for each pixel we will
        // draw all eight pixels
        circlePlotPoints(xc, yc, x, y);
        x++;

        // check for decision parameter
        // and correspondingly
        // update d, x, y
        if (d > 0)
        {
            y--;
            d = d + 4 * (x - y) + 10;
        }
        else
            d = d + 4 * x + 6;
        circlePlotPoints(xc, yc, x, y);
        delay(50);
    }
}
void circlePlotPoints (int xCenter, int yCenter, int x, int y)
{
 putpixel (xCenter + x, yCenter + y,WHITE);
 putpixel (xCenter - x, yCenter + y,WHITE);

 putpixel (xCenter + x, yCenter - y,WHITE);
 putpixel (xCenter - x, yCenter - y,WHITE);

 putpixel (xCenter + y, yCenter + x,WHITE);
 putpixel (xCenter - y, yCenter + x,WHITE);

 putpixel (xCenter + y, yCenter - x,WHITE);
 putpixel (xCenter - y, yCenter - x,WHITE);
}
