#include <iostream> 
using namespace std;

int main()
{
   //Declaring all variables
int touchdowns=0; // declare and define touchdowns

int extrapoints=0;

int fieldgoals=0;

int safetys=0;

int sum=0;  

cout<<"Enter amount of touchdowns: ";
cin>>touchdowns;

cout<<"Enter the amount of extrapoints: ";
cin>>extrapoints;


cout<<"Enter amount of fieldgoals: ";
cin>>fieldgoals;

cout<<"Enter the amount of safetys: ";
cin>>safetys;

sum = touchdowns*6 + extrapoints*1 + fieldgoals*3 +safetys*2;

cout<<"Sum is: "<<sum<<endl;

return 0;

}

