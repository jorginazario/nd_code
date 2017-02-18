#include <iostream>
#include <cmath>
using namespace std;

int main(){

  int nums[50];
  double  sum=0;
  double avg=0;
  double stdsum=0;
  double  stdm=0;
  double stdf=0;
  int a,i,j=0;
  
  //Request user to input numbers
  cout<<"Enter a few positive numbers (not more than 50 of them)"<<endl; 
  cout<<"from the keyboard, followed by a -1: "<<endl;
  cin>>a;
 
  //Keep reading the input numbers until -1 is an input
  while (a!=-1) {
    nums[i]=a;
    i++;
    cin>>a;
  } 
  
  //Add all of the numbers
  for (int k=0; k<i; k++){
    sum+=nums[k]; 
  }

  //comute average of all the input grades
  avg=(sum/i); 
  
  //compute standar deviation
  for (int p=0; p<i; p++) {
   stdsum+=(nums[p]-avg)*(nums[p]-avg);
  }

  stdm=stdsum/i;
  stdf=sqrt(stdm);
  
  //Display sum, average, and standar deviation
  for (j=0; j<i; j++){
    cout <<nums[j]<<" ";
  }
  cout<<" "<<endl;
  cout<<"Their sum is: "<<sum<<endl;
  cout<<"The average is: "<<avg<<endl;
  cout<<"The standard deviation is: +-"<<stdf<<endl;

return 0;
}

