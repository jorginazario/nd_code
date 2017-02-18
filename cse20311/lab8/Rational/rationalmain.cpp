// simple driver to test the Rational class
#include <iostream>
using namespace std;
#include "rational.h"

int main()
{
  //initialize all variables
  Rational a,b,c,s,sub,m,d; 
  int x,y,w,z;

  //Request user to input values for first and second rational number
  cout<<"Enter your first rational number (enter numer, press enter; enter denom, press enter):";
  cin>>x>>y;
  cout<<"Enter your second rational number (enter numer, press enter; enter denom, press enter): ";
  cin>>w>>z;
  a.setRational(x,y); //save the separated numer and denom together under the rational 'a'
  b.setRational(w,z);

  //Display both rational numbers
  cout << "*** display a and b ***\n"<<endl;
  cout<<a<<endl;
  cout<<b<<endl;
  cout << "*** display c ***\n"<<endl;
  cout<<c<<endl;  // recall that c was instantiated with the default constructor

  // 'mathematically' add a and b
  cout << "*** compute s as the math sum of a and b, and display s ***\n"<<endl;
  s = a+b;
  cout<<s<<endl;  
  
  //'mathematically' subtracts a and b
  cout << "*** compute sub as the math subtraction of a and b, and display sub ***\n"<<endl;
  sub = a-b;
  cout<<sub<<endl;

  //'mathematically' mulitplies a and b
  cout << "*** compute m as the math multiplication of a and b, and display m ***\n"<<endl;
  m = a*b;
  cout<<m<<endl;
  
  //'mathematically' divide a and b
  cout << "*** compute d as the math division of a and b, and display d ***\n"<<endl;  
  d = a/b;
  cout<<d<<endl;

  return 0;
}
  
