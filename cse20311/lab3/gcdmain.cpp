#include <iostream>
#include <cmath>

using namespace std;

int getgcd(int, int);

int main()
{
  int a,b,g=0;
  cout<<"Enter two numbers to compute the Greatest Common Divisor."<<endl;
  cout<<"Enter first number: ";
  cin>>a;

  cout<<"Enter second number: ";
  cin>>b;

  g=getgcd(a,b);
  cout<<"GCD: "<<g<<endl;
  return 0;

}

int getgcd(int a, int b)
{
  int g=0;
  int i=0;
    for (i=1; i<=a && i<=b; i++) 
	{
          if(a%i==0 && b%i==0)
	    {
	      g=i;
	    }
	}
   return g;
	
}
