// factrec.cpp
// factorial with a recursive function 

#include <iostream>
using namespace std;

double fact2(int);

int main()
{
  int n;

  cout << "Enter a number: ";
  cin >> n;

  cout << "its factorial is " <<  fact2(n) << endl;

  return 0;
}

double fact2(int n)
{
  double f;

  if(n == 1 || n == 0)
    f = 1;
  else
    f = n*fact2(n-1);

  return f;

  // or just simply: 
  //   return (n == 1 || n == 0) ? 1 : n*fact2(n-1);
}

