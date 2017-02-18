#include <iostream>
#include <cmath>

using namespace std;

int main(){
  
  int prime[1000];
  int i=2;
  
  prime[0]=0;
  prime[1]=0;
  
  for (i=2;i<1000;i++){
    prime[i]=1;
  }

  for (i=2;i<1000;i++){
    if (prime[i]=0){
      continue;
    }

    int k=2;
    int t=i*k;  

    while (t<1000){    
      t=i*k;
      prime[t]=0;
      k++;
    }
  }
  for (int i=0; i<1000;i++){
    if (prime[i]=1){
      cout<<i<<" ";
    }
  }
}
