#include <iostream>
#include <cmath>

using namespace std;

double polarlength(double,double);
double polarangle(double,double);

int main()
{
  double x,y,r,a=0;
  cout<<"Input the x value of your coordinate: ";
  cin>>x;

  cout<<"Input the y value of your coordinate: ";
  cin>>y;

  r=polarlength(x,y);
  a=polarangle(x,y);  

  cout<<"Your polar coordinate is: ("<<r<<", "<<a<<")"<<endl;  
  
  //If Statements for identifying if in Origin, Y or X axis, or Quadrant
  if (x==0 && y==0)
  {
    cout<<"Your point is at the Origin"<<endl;
  }
  else if (y==0)
  {
    cout<<"On the X axis"<<endl;
  }
  else if (a<90)
  {
    cout<<"Quadrant: I"<<endl;
  }
  else if (x==0)
  {
    cout<<"On the Y axis"<<endl;
  }
  else if (a>90 && a<180)
  {
    cout<<"Quadrant: II"<<endl;
  }
  else if (a>180 && a<270)
  {
    cout<<"Quadrant: III"<<endl;
  }
  else if (a>270 && a<360)
  {
    cout<<"Quadrant: IV"<<endl;
  }
  
                                         
}

double polarlength(double x,double y)
{
  double r=0;
  r=sqrt(x*x + y*y);
  return r;
}

double polarangle(double x, double y)
{ 
  double a=0;
  
  a=atan(y/x);
  a=(a/(2*3.14159))*360;
    if (x==0 && y==0)
    {
      a=0;
    }
    else if (x<0 && y>0)
    {
      a=180+a;
    }
    else if (x<0 && y<0)
    {
      a=180+a;
    }
    else if (x>0 && y<0)
    {
      a=360+a;  
    }
    else if (x==0 && y<0)
    {
      a=270;
    }
    else if (x==0 && y>0)
    {
      a=90;
    }
    else if (y==0 && x>0)
    {
      a=0;
    }
    else if (y==0 && x<0)
    {
      a=180;
    }
  return a;
}

