// fibonacci.cpp
// Fibonacci with a recursive function 

#include <iostream>
using namespace std;

int fib(int);

int main()
{
  int n;

  cout << "Enter a number: ";
  cin >> n;

  cout << "fibonacci of " << n << " is " << fib(n) << endl;

  return 0;
}

int fib(int n)
{
  if(n == 0 || n == 1) return n;  // base case
  int f = fib(n-1) + fib(n-2);    // recursive call

  return f;
}

