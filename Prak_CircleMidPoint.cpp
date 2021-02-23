
#include<windows.h>
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
#include<stdio.h>
#include <stdlib.h>

void circleMidpoint (int xCenter, int yCenter, int radius){
 int x = 0;
 int y = radius;
 int p = 1 - radius;
 void circlePlotPoints (int, int, int, int);
 // Plot first set of points
 circlePlotPoints (xCenter, yCenter, x, y);
 while (x < y) {
  x++;
  if (p < 0){
   p += 2 * x + 1;
  }
  else {
   y--;
   p += 2 * (x - y) + 1;
  }
  circlePlotPoints (xCenter, yCenter, x, y);
 }
}
void circlePlotPoints (int xCenter, int yCenter, int x, int y)
{
 SetPixel(xCenter + x, yCenter + y);
 SetPixel (xCenter - x, yCenter + y);

 SetPixel (xCenter + x, yCenter - y);
 SetPixel (xCenter - x, yCenter - y);

 SetPixel (xCenter + y, yCenter + x);
 SetPixel (xCenter - y, yCenter + x);

 SetPixel (xCenter + y, yCenter - x);
 SetPixel (xCenter - y, yCenter - x);
}
