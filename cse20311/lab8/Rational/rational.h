// rational.h
#include <iostream>
using namespace std;

class Rational {
 friend ostream& operator<< (ostream &, Rational &);
 friend istream& operator>> (istream &, Rational &);
  public:
    Rational();
    Rational(int, int);
    ~Rational();
    int getNumer();
    int getDenom();
    void setRational(int, int);
    //void setNumer(int);
    //void setDenom(int);
    void print();
    Rational operator+(Rational);
    Rational operator-(Rational);
    Rational operator*(Rational);
    Rational operator/(Rational);
  private:
    int numer;
    int denom;
};

