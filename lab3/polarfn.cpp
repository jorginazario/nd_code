#include <iostream>
#include <cmath>

using namespace std;

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
