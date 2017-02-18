// Juan Pablo Borrero & Jorge Nazario
// CSE 20311
// FINAL PROJECT
//
// Main driver

#include <unistd.h>
#include "gfxnew.h"
#include <cstdlib>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <cmath>
#include <string>
#include <cstring>
#include <iostream>
using namespace std;

#define XC_shuttle 118
#define win_wd 700
#define win_ht 600

void display_background(); // BACKGROUND ON THE BACK
void drawShip (int,int);
void shoot(int, int &, int &);
void drawTarget1(int &, int &, int &);
void drawTarget2(float &, float &, float);
void checkHit(int, int &, int, int, float, float, int &);
void dispScore(int &, int);
void explosion1();
void explosion2();
void ball(float, float);
void drawPolygon(int,double, double);
void drawInvertedShip(int , int);

//MAIN FUNCTION
int main(){
	int xc=win_wd/2, yc=500;			  //ship x and y coordinates
	int txc, tyc = 100, vx=4;		    //target x and y coordinates and velocity of target, need it for comparison reasons
  int sxc, syc = yc - 10;         //shot x and y coordinate for comparison purposes
	float t2xc = 350, t2yc = 100, angle = 0;       // target 2 coordinates
	int score = 0;
  int count_shots = 0;
  char c;
  bool loop=true;

	gfx_open(win_wd,win_ht,"Galaga");
	gfx_changecursor(XC_shuttle);

	while (loop){
      gfx_clear();
      display_background();
			dispScore(score, count_shots);
			drawShip(xc,yc);
      drawTarget1(txc, tyc, vx);
      drawTarget2(t2xc, t2yc, angle);
			if (syc > 0 && syc < 490) // To check if a shot has been fired
				shoot(xc, sxc, syc);

			//Function checks if shot hit the target
			checkHit(sxc,syc,txc,tyc,t2xc,t2yc,score);

			gfx_flush();
      usleep(20000);

			if (gfx_event_waiting()){
				c=gfx_wait();
				switch(c){
          case 'S': //MOVE SHIP RIGHT
          case 'd':
						xc = xc + 10;
            if (xc >= win_wd)
          		xc = win_wd - 5;
						break;
          case 'Q': //MOVE SHIP LEFT
					case 'a': 
						xc = xc - 10;
            if (xc <= 0)
          		xc = 5;
            break;
					case ' ': //SHOOT
						shoot(xc, sxc, syc);
            count_shots++;
						break;
					case 'q': //QUIT PROGRAM
						loop = false;
						break;
				}
			}
			if (angle == 2*M_PI)
      	angle = 0;
    	angle += M_PI/50;
    	if (count_shots == 22){
      	break;
    }
	}
  cout << "Your score is: " << score << endl;
  return 0;
}

// DISPLAY BACKGROUND
void display_background(){
  gfx_color(135, 206, 235); // Sky
  gfx_fill_rectangle(0, 0, 700, 600);

  gfx_color(255,255,255); // Clouds
  for (int j = 150; j > 100; j = j - 25)
    for (int i = 150 - j; i <= 100; i=i+40)
      gfx_fill_circle(150+i, j, 30);

  for (int j = 200; j > 150; j = j - 25)
    for (int i = 200 - j; i <= 100; i=i+40)
      gfx_fill_circle(450+i, j, 30);

  gfx_color(128,128,128); // Buildings
  gfx_fill_rectangle(100,350,100,250);
  gfx_fill_rectangle(300,400,100,200);
  gfx_fill_rectangle(475,275,100,325);

  gfx_color(255,255,0); // Windows
  for (int j = 0; j < 200; j=j+40)
    for (int i = 0; i < 50; i=i+40)
      gfx_fill_rectangle(120+i,375+j,20,20);

  for (int j = 0; j < 150; j=j+40)
    for (int i = 0; i < 50; i=i+40)
      gfx_fill_rectangle(320+i,415+j,20,20);

  for (int j = 0; j < 250; j=j+40)
    for (int i = 0; i < 50; i=i+40)
      gfx_fill_rectangle(495+i,300+j,20,20);

  gfx_color(0,0,0);
  gfx_fill_rectangle(140,570,20,30); // Doors
  gfx_fill_rectangle(340,570,20,30);
  gfx_fill_rectangle(515,570,20,30);

}

// DISPLAY SHIP
void drawShip(int x, int y){
  gfx_color(255,153,51);
  gfx_fill_rectangle(x-10,y-20,20,40);
  gfx_color(255,255,0);
  gfx_fill_arc(x-10,y-30,20,20,0,180);
  gfx_fill_rectangle(x-5,y+20,10,10);
  gfx_color(0,102,0);
  XPoint a[] = {x-10,y,x-35,y+20,x-10,y+20};
  gfx_fill_polygon(a,3);
  XPoint b[] = {x+10,y,x+35,y+20,x+10,y+20};
  gfx_fill_polygon(b,3);

}

//DISPLAY SCORE
void dispScore(int &score, int count_shots){
  int shots = 10 - count_shots/2;
  string Score, str_score, Shots, str_shots;
  str_score = to_string(score);
  str_shots = to_string(shots);
  Score = "Score: ";
  Shots = "Shots remaining: ";
  Score.append(str_score);
  Shots.append(str_shots);
	gfx_color(0,0,0);
	gfx_text(20,25, "Rules: Shoot the blue UFO for 10pts and the red one for 5 pts. You have 10 shots."); // gfx_waiting double counts so only 10 shots instead of 20
	gfx_text(620,25, Score.c_str());
  gfx_text(20, 45, Shots.c_str());
}

//SHOOTING
void shoot(int xc, int &sxc, int &syc){
  int dt=1;
	int svy = 10;				//shot velocity in the y-direction

  sxc = xc;
	gfx_color(255,255,0);
	gfx_fill_circle(sxc,syc,5);
	syc = syc - svy*dt;				//update the shooting ball position
	if (syc<=0)
		syc = 490; // So the shot stops and is not run in main
}

//TARGET 1 MOTION
void drawTarget1(int &txc, int &tyc, int &vx){
	int target1_rad1 = 50, target1_rad2 = 20;
	int dt = 1; // For consistency

	gfx_color(0,0,255);
  for (double i = target1_rad1, j = target1_rad2; i >= 0, j >=0; i-=0.1,j-=0.1)
    gfx_ellipse(txc,tyc,i,j);
  gfx_color(255,255,255);
  gfx_fill_arc(txc-20,tyc-30,40,35,0,180);
	txc = txc + vx*dt;

	if (txc >= win_wd - target1_rad1 || txc <= target1_rad1){
		vx = -vx;
    if (txc > win_wd/2)
      txc=win_wd-target1_rad1;
    else
		  txc=target1_rad1;
	}
}
//TARGET 2 MOTION
void drawTarget2(float &t2xc, float &t2yc, float angle){
  int target2_rad1 = 40, target2_rad2 = 20;
  int rotr = 5;

  gfx_color(255,0,0);
  for (double i = target2_rad1, j = target2_rad2; i >= 0, j >=0; i-=0.1,j-=0.1)
    gfx_ellipse(t2xc,t2yc,i,j);
  gfx_color(255,255,255);
  gfx_fill_arc(t2xc-18,t2yc-30,35,30,0,180);
  t2xc=t2xc+rotr*cos(angle);
  t2yc=t2yc+rotr*sin(angle);
}

//CHECK FOR HIT
void checkHit(int sxc, int &syc, int txc, int tyc, float t2xc, float t2yc, int &score){
	//CHECK CONDITIONS FOR HIT
	//HORIZONTAL MOTION BALL
	if (pow((sxc-txc)*(sxc-txc)+(syc-tyc)*(syc-tyc),0.5) <= 40){
		explosion2();
		score+=10; syc=490;
	}
	//FOR ROTATING BALL
  if (pow((sxc-t2xc)*(sxc-t2xc)+(syc-t2yc)*(syc-t2yc),0.5) <= 30){
		explosion1();
		score+=5; syc=490;
	}
}

//FIGURE EXPLOSIONS
void explosion1(){
  double size = 50;
  gfx_clear();
	while (size < 700){
    gfx_color(135, 206, 235); // Sky
    gfx_fill_rectangle(0, 0, 700, 600);
    // draw explosion
		gfx_color(255,255,0);
		drawPolygon(3,size,0);
    drawPolygon(3,size,M_PI);
	  gfx_color(255,0,0);
    drawPolygon(3,size*0.7,0);
    drawPolygon(3,size*0.7,M_PI);
    gfx_color(255,255,0);
		drawPolygon(3,size*0.4,0);
    drawPolygon(3,size*0.4,M_PI);
    gfx_color(255,0,0);
    drawPolygon(3,size*0.2,0);
    drawPolygon(3,size*0.2,M_PI);
    size = size + 10;
    gfx_flush();
		usleep(30000);
	}
}

void drawPolygon(int sides, double size, double angle){ // Used in explosion 1
  int x1,y1,x2,y2,x3,y3,x,y;
  double theta = 2*M_PI/sides;
  x = win_wd/2; y = win_ht/2;
  x1 = x + size*cos(0*theta+angle);
  y1 = y + size*sin(0*theta+angle);
  x2 = x + size*cos(1*theta+angle);
  y2 = y + size*sin(1*theta+angle);
  x3 = x + size*cos(2*theta+angle);
  y3 = y + size*sin(2*theta+angle);
  XPoint pointsarr[]= {x1,y1,x2,y2,x3,y3};
  gfx_fill_polygon(pointsarr, 3);
}

void explosion2(){
	float vx=1.5,vy=2;;								//Initial velocity
	float svx=10;							//laser shot velocity
	float dt=1; 							//mult. factor of time
	float xc=0, yc=75;  			//demo circle center
	float sx=250;
	float sy=300;
	bool loop=true;
	int counter=0;
  int txc = 600, tyc = 500, vel = 0; // for UFO target

  gfx_color(135, 206, 235); // Sky
  gfx_fill_rectangle(0, 0, 700, 600);
  gfx_flush();
  usleep(10000);
	while (loop){
    gfx_clear();
    gfx_color(135, 206, 235); // Sky
    gfx_fill_rectangle(0, 0, 700, 600);
		drawInvertedShip(xc,yc);
    drawTarget1(txc,tyc,vel);
		gfx_flush();
    usleep(10000);
		//move ship horizontally to the right
		while (xc<=300){
      gfx_clear();
      gfx_color(135, 206, 235); // Sky
      gfx_fill_rectangle(0, 0, 700, 600);
      vy=0.5;
			xc=xc+vx*dt;
			yc=yc+vy*dt;
			drawInvertedShip(xc,yc);
      drawTarget1(txc,tyc,vel);
			gfx_flush();
			usleep(10000);
		}

		while (xc>=250){
			gfx_clear();
      gfx_color(135, 206, 235); // Sky
      gfx_fill_rectangle(0, 0, 700, 600);
      xc=xc-vx*dt;
			drawInvertedShip(xc,yc);
      drawTarget1(txc,tyc,vel);
			gfx_flush();
			usleep(10000);
		}
		while (yc<=500){
			vy=1.5;
			gfx_clear();
      gfx_color(135, 206, 235); // Sky
      gfx_fill_rectangle(0, 0, 700, 600);
      yc=yc+vy*dt;
		  drawInvertedShip(xc,yc);
      drawTarget1(txc,tyc,vel);
			gfx_flush();
			usleep(10000);
		}
		sx=xc;
		sy=yc;

		while (sx<=500){
			gfx_clear();
      gfx_color(135, 206, 235); // Sky
      gfx_fill_rectangle(0, 0, 700, 600);
      //draw original ship
			drawInvertedShip(xc,yc);
      drawTarget1(txc,tyc,vel);
			ball(sx+50,sy); //draw laser shot
			gfx_flush();
			usleep(10000);
			sx=sx+svx*dt;
			if (sx>=500){
				counter+=1;
			}
			if (counter==2){
				loop=false;
			}
		}
	}
  explosion1();
}

//SIMPLE BALL (USED AS LASER SHOT)
void ball(float sx, float sy){
	//draw laser shot
	gfx_color(255,255,0);
  gfx_fill_circle(sx,sy,10);
}

void drawInvertedShip(int x, int y){ // For the explosion 2 scene
  gfx_color(255,153,51);
  gfx_fill_rectangle(x-20,y-10,40,20);
  gfx_color(255,255,0);
  gfx_fill_arc(x+5,y-10,30,20,-90,180);
  gfx_fill_rectangle(x-30,y-5,10,10);
  gfx_color(0,102,0);
  XPoint a[] = {x,y-10,x-20,y-35,x-20,y-10};
  gfx_fill_polygon(a,3);
  XPoint b[] = {x,y+10,x-20,y+35,x-20,y+10};
  gfx_fill_polygon(b,3);

}
