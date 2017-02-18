#include <iostream>
#include <cmath>
#include "polarfn.h"

using namespace std;


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
