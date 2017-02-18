#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

int main(){
  
  int prime[1000];
  int i=2;
  int k=2;
  int t=0;
  int linecount=1;

  prime[0]=0;
  prime[1]=0;
  
  //Assign 1's to all elements in the array
  for (i=2;i<1000;i++){
    prime[i]=1;
  }

  //Non prime numbers will be changed to 0's, if the element is 0 already it will be skipped.
  for (i=2;i<1000;i++){
    if (prime[i]==0){
      continue;
    }

    while (t<1000){    
      t=i*k;
      if (t<1000){
        prime[t]=0;
      }
      k++;
    }
    k=2;
    t=0;
  }

  //Print the prime numbers
  for (int i=0; i<1000;i++){
    if (prime[i]==1){
      cout<<setw(8)<<i;
        if (linecount==8){
          cout<<" "<<endl;
          linecount=0;        
        }
      linecount++;
    }
  }
}
