// countdown.cpp
// counting down from a number down to 0
#include <iostream>
using namespace std;

void down(int);   // using a loop
void down2(int);  // using recursion

int main()
{
  int n;

  cout << "enter an integer: ";
  cin >> n;

  down(n);
  down2(n);

  return 0;
}

void down(int n) 
{
  for(int i = n; i >= 0; i--)
    cout << i << endl;
}

void down2(int n) 
{
  cout << n << endl;
  if(n != 0) down2(n-1);
}

