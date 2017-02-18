#include <iostream>
using namespace std;

int main(){

int x1=0;
int y1=0;
int z1=0;

int x2=0;
int y2=0;
int z2=0;
int dotp=0;

cout <<"To compute the dot product of two vectors enter the <x1,y1,z1> of the first vector and the <x2,y2,z2> for the second vector.";
cout<<"Input x1: ";
cin>>x1;
cout<<"Input y1: ";
cin>>y1;
cout<<"Input z1: ";
cin>>z1;

cout<<"Input the <x,y,z> of your second vector. Input x2: ";
cin>>x2;
cout<<"Input y2: ";
cin>>y2;
cout<<"Input z2: ";
cin>>z2;


dotp=(x1*x2)+(y1*y2)+(z1*z2);

cout<<"Your dot product is: "<<dotp<<endl;
return 0;





}
