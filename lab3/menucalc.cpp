#include <iostream>
#include <cmath>

using namespace std;

double addition(double,double);
double subtraction(double,double);
double multiplication(double,double);
double division(double,double);

int main()
{
  double a,b,s,r,m,d=0;
  int c=0;
  while (c==0)
  {
    cout<<"What would you like to do?"<<endl;
    cout<<"\t"<<"1 for addition"<<endl;
    cout<<"\t"<<"2 for subtraction"<<endl;
    cout<<"\t"<<"3 for multiplication"<<endl;
    cout<<"\t"<<"4 for division"<<endl;
    cout<<"\t"<<"5 to exit"<<endl;
    cout<<"Enter your choice: ";
    cin>>c;
    while (c!=1 && c!=2 && c!=3 && c!=4 && c!=5 && c!=0)
    {
      cout<<"Invalid number please try again."<<endl;
      cout<<"What would you like to do?"<<endl;
      cout<<"\t"<<"1 for addition"<<endl;
      cout<<"\t"<<"2 for subtraction"<<endl;
      cout<<"\t"<<"3 for multiplication"<<endl;
      cout<<"\t"<<"4 for division"<<endl;
      cout<<"\t"<<"5 to exit"<<endl;
      cout<<"Enter your choice: ";
      cin>>c;
    }  
    if (c==5)
    {
       cout<<"Thank you!"<<endl;
       return 0;
    }
    cout<<"Enter two numbers."<<endl;
    cout<<"Enter first number: ";
    cin>>a;
    cout<<"Enter second number: ";
    cin>>b;
    cout<<"Inputs: "<<a<<", "<<b<<endl;

    if (c==1)
    {
      s=addition(a,b);
      cout<<a<<"+"<<b<<"="<<s<<endl;
      c=0;
    }
    else if (c==2)
    {
      r=subtraction(a,b);
      cout<<a<<"-"<<b<<"="<<r<<endl;
      c=0;
    }
    else if (c==3)
    {
      m=multiplication(a,b);
      cout<<a<<"*"<<b<<"="<<m<<endl;
      c=0;
    }
    else if (c==4)
    {
      d=division(a,b);
      cout<<a<<"/"<<b<<"="<<d<<endl;
      c=0;
    }
                 
  }
}

double addition(double a, double b)
{
  double s=0;
  s=a+b;
  return s;
}
double subtraction(double a, double b)
{
  double r=0;
  r=a-b;
  return r;
}
double multiplication(double a, double b)
{
  double m=0;
  m=a*b;
  return m;
}
double division(double a, double b)
{
  double d=0;
  d=(a/b);
  return d;
}




