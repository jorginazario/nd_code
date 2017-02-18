// numrev.cpp
// displays digits of a number in reverse order
#include <iostream>
using namespace std;

void flipit(int n);   // using a loop
void flipit2(int n);  // using recursion

int main()
{
  int n;

  cout << "enter an integer: ";
  cin >> n;

  flipit(n);
  flipit2(n);

  return 0;
}

void flipit(int n) 
{
  while(n != 0) {
    cout << n%10 << endl;
    n = n/10;
  }
}

void flipit2(int n) 
{
  cout << n%10 << endl;
  if (n > 10 ) flipit2(n/10); 
}

