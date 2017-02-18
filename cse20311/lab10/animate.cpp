#include <unistd.h>
#include "gfx.h"
#include <cstdlib>
#include <time.h>
#include <cmath>

//make the triangle big and rotate 360 degrees with a slow moving ball in the middle. If the soccer ball hits the ball inside the triangle then you win

void rotation(float &, float &, float &, float &, float &, float, float, float &, float &, char &);

int main(){
	
	//initialize values
	int wd=700, ht=600;   		//window width and height
	float xc=50, yc=500;  		//white ball initial position							
	float R=30;
	float r=20;							
	char c='1';
	float vx=10,vy=-10;				//Initial velocity 
	int dt=3; 								// mult. factor of time
	float tx=350, ty=200;  		//triangle center
	float theta=0.5, RotR=50;
	float x1=350, y1=100;
	
	gfx_open(wd,ht,"Animation"); //open window
	
	while (c!='q'){
							
			
		rotation(xc,yc,x1,y1,R,theta,RotR,vx,vy,c);	
			
			//Draw triangle on screen		
			/*gfx_color(0,255,0);
			gfx_line(tx-25,ty-25, tx+25,ty-25);
			gfx_line(tx-25,ty-25, tx,ty+25);
			gfx_line(tx+25,ty-25, tx,ty+25);
			*/
			
			//usleep(10000000);
		
			if (c=='s'){
				while (yc>0){	
					gfx_clear();
					gfx_color(0,0,255);	 		//draw blue ball
					gfx_circle(x1,y1,r);
					gfx_flush();
				
					gfx_color(255,255,255); //draw white ball
					gfx_circle(xc,yc,R);		
					gfx_flush();
											
					yc=yc+vy*dt;	 					//update white ball location
					usleep(100000);	
					
					if ((xc-R)<(x1+r) && (xc-R)>(x1-r) && (yc-R)>(y1-r) && (yc-R)<(y1+r)){
						//triangle explosion
						gfx_clear();
						gfx_color(255,0,0);
						gfx_line(tx-25,ty-25, tx+25,ty-25);
						gfx_line(tx-25,ty-25, tx,ty+25);
						gfx_line(tx+25,ty-25, tx,ty+25);
						gfx_flush();
						usleep(1000000);						
					}	
					if ((xc+R)>(x1-r) && (xc+R)<(x1+r) && (yc+R)>(y1-r) && (yc+R)<(y1+r)){
						//triangle explosion
						gfx_clear();
						gfx_color(255,0,0);
						gfx_line(tx-25,ty-25, tx+25,ty-25);
						gfx_line(tx-25,ty-25, tx,ty+25);
						gfx_line(tx+25,ty-25, tx,ty+25);
						usleep(1000000);
						
					}
				}
				
				if (yc<=0){
					yc=500;
				}
				c='1';
			}	
			
	}
	return 0;
}

void rotation(float &xc, float &yc, float &x1, float &y1, float &R, float theta, float rotr, float &vx, float &vy, char &c){
	
	int wd=700, ht=600;   //window width and height
	int dt=3;
	theta=0;
	x1=350;
  y1=100;
  c='1';
	
	for (float angle=theta; angle<=2*M_PI;angle+=(M_PI/8)){
		
		gfx_clear();
		
		gfx_color(0,0,255);	
		x1=rotr*cos(angle)+x1;
		y1=rotr*sin(angle)+y1;
		gfx_circle(x1,y1,R-10);
		gfx_flush();
		
		gfx_color(255,255,255);
		gfx_circle(xc,yc,R);
		gfx_flush();
		xc=xc+vx*dt;
		
		if (xc>=wd){ 
			vx=-vx;
			xc=wd-25;
		}
		if (xc<=0){
			vx=-vx;
			xc=25;
		}	
		
		usleep(50000);
		
		if (gfx_event_waiting()){
			c=gfx_wait();
			if (c=='s'){
				return;
			}			
		}
	}
}


