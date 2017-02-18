// Fractal 1


#include <iostream>
#include <cmath>
#include <cstdlib>
#include "gfxnew.h"

using namespace std;

void drawSierpinski(int, int, int, int, int, int);
void drawtriangle(int, int, int, int, int, int);

int main(){
  const int wd = 800, ht = 800;
  int x1,x2,x3,y1,y2,y3;
  char c = ' ';
  double angle;

  gfx_open(wd, ht, "Fractals");

  while (1){
    gfx_clear();
    angle = M_PI/3;
    x1 = (wd/2)-300;
    y1 = (ht/2)+300;
    x2 = (wd/2)+300;
    y2 = (ht/2)+300;
    x3 = (wd/2);
    y3 = (ht/2)-300;
    drawSierpinski(x1,y1,x2,y2,x3,y3);
    if (c = gfx_wait() == 'q')
      break;
  }

}

void drawSierpinski(int x1, int y1, int x2, int y2, int x3, int y3){
 // Draw the triangle
 drawtriangle( x1, y1, x2, y2, x3, y3 );
 // Base case.
 if( abs(x2-x1) < 15) return;
 // Recursive calls
 drawSierpinski( x1, y1, (x1+x2)/2, (y1+y2)/2, (x1+x3)/2, (y1+y3)/2 );
 drawSierpinski( (x1+x2)/2, (y1+y2)/2, x2, y2, (x2+x3)/2, (y2+y3)/2 );
 drawSierpinski( (x1+x3)/2, (y1+y3)/2, (x2+x3)/2, (y2+y3)/2, x3, y3 );
}

void drawtriangle(int x1, int y1, int x2, int y2, int x3, int y3){
  gfx_line(x1, y1, x2, y2);
  gfx_line(x2, y2, x3, y3);
  gfx_line(x3, y3, x1, y1);
}
