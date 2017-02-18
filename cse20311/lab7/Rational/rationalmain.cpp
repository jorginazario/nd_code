// simple driver to test the Rational class
#include <iostream>
using namespace std;
#include "rational.h"

int main()
{
  Rational a(5,6), b(3,7), c, s, sub,  m, d;

  cout << "*** display a and b ***\n";
  a.print();
  b.print();
  cout << "*** display c ***\n";
  c.print();  // recall that c was instantiated with the default constructor

  // 'mathematically' add a and b
  cout << "*** compute s as the math sum of a and b, and display s ***\n";
  s = a.add(b);
  s.print();
  
  //'mathematically' subtracts a and b
  cout << "*** compute sub as the math subtraction of a and b, and display sub ***\n";
  sub = a.subtract(b);
  sub.print();

  //'mathematically' mulitplies a and b
  cout << "*** compute m as the math multiplication of a and b, and display m ***\n";
  m = a.multiply(b);
  m.print();
  
  //'mathematically' divide a and b
  cout << "*** compute d as the math division of a and b, and display d ***\n";  
  d = a.divide(b);
  d.print();

  return 0;
}
  
