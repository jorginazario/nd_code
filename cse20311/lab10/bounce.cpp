//bounce.cpp
// animating a ball at a given direction and speed
// and making it bounce against the walls

#include <unistd.h>
#include "gfx.h"
#include <cstdlib>
#include <time.h>

int main() {
  int win_wd = 600, win_ht = 500;  // window width and height
  float xc = 100, yc = 100;        // ball initial center
  int rad = 20;                    // ball radius
  float vx = 1, vy = 1;            // velocity vector
  float dt = 3;                    // mult. factor (here, same for both x&y; needn't be)
  char c = ' ';
  srand(time(NULL));

  gfx_open (win_wd, win_ht, "Moving Ball");

  while(c != 'q') {
    gfx_clear();
    gfx_color(255,255,255);
    
    gfx_circle(xc, yc, rad);
    gfx_flush();
    xc = xc + vx*dt;
    yc = yc + vy*dt;

    // walls collision detection
    // (note: we could combine the first two with an OR (||),
    // and same for the last two; code shown here as such
    // for descriptive purposes)
    if (xc > win_wd-rad){       // right wall
       vx = -vx;
       xc = win_wd-rad;
    }
    else if (xc < rad){        // left wall
       vx = -vx;
       xc = rad;
    }
    else if (yc > win_ht-rad){  // bottom wall
       vy = -vy;
       yc = win_ht-rad;
    }
    else if (yc < rad){         // top wall
       vy = -vy;
       yc = rad;
		}
    gfx_flush();
    usleep(10000);
    
    if(gfx_event_waiting()){
       c = gfx_wait();
       if (c=1){       		
       		xc=gfx_xpos();
       		yc=gfx_ypos();
       		vx=rand()%5-rand()%5;
       		vy=rand()%5-rand()%5;       		
       		if (vx==0 && vy==0){
       			vx=1;
       			vy=-1;
       		}
       	}	
     }
  }

  return 0;
}
