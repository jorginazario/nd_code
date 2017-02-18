#include <cmath>
#include <iostream>
#include "rational.h" //(prototype)

using namespace std;

Rational::Rational()
{ numer=1; denom=1;}

Rational::Rational(int n, int d)
{numer=n; denom=d;}

Rational::~Rational(){ } //nothing to be done (yet)

int Rational::getNumer()
{return numer;}

int Rational::getDenom()
{return denom;}

void Rational::print()
{numer=getNumer();
denom=getDenom();
cout<<numer<<"/"<<denom<<endl;}

void Rational::setRational(int n, int d)
{numer=n; denom=d;}

Rational Rational::operator+(Rational b){
Rational c;
c.numer=numer*b.getDenom()+denom*b.getNumer();
c.denom=denom*b.getDenom();
return c;}

Rational Rational::operator-(Rational b){
Rational c;
c.numer=numer*b.getDenom()-denom*b.getNumer();
c.denom=denom*b.getDenom();
return c;}

Rational Rational::operator*(Rational b){
Rational c;
c.numer=numer*b.getNumer();
c.denom=denom*b.getDenom();
return c;}

Rational Rational::operator/(Rational b){
Rational c;
c.numer=numer*b.getDenom();
c.denom=denom*b.getNumer();
return c;}

//overload the output stream
ostream& operator<< (ostream &s, Rational &c)
{
  s << c.numer << "/" << c.denom;
  return s;
}

//overload the input stream
istream& operator>> (istream &s, Rational &c)
{
  int n, d;

  cout << "Enter the numerator and denominator of your rational: ";

  return s;
}
