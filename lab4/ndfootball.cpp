#include <iostream>
#include <cmath>

using namespace std;

int main(){
  int wins[]=
   { 6, 8, 6, 8, 5, 5, 6, 6, 8, 7, 4,
   6, 7, 7, 6, 7, 8, 6, 3, 9, 9, 10,
   8, 9, 10, 7, 9, 7, 5, 9, 10, 6, 6,
   3, 6, 7, 6, 6, 8, 7, 7, 8, 7, 9,
   8, 7, 8, 9, 9, 10, 4, 7, 7, 9, 9,
   8, 2, 7, 6, 5, 2, 5, 5, 2, 9, 7,
   9, 8, 7, 8, 10, 8, 8, 11, 10, 8, 9,
   11, 9, 7, 9, 5, 6, 7, 7, 5, 5, 8,
   12, 12, 9, 10, 10, 11, 6, 9, 8, 7, 9,
   5, 9, 5, 10, 5, 6, 9, 10, 3, 7, 6,
   8, 8, 12, 9, 8, 10 };


  int losses[] = 
   { 3, 1, 2, 0, 3, 4, 1, 0, 1, 0, 1,
   0, 0, 0, 2, 1, 1, 1, 1, 0, 0, 1,
   1, 1, 0, 2, 1, 1, 4, 0, 0, 2, 2,
   5, 3, 1, 2, 2, 1, 2, 2, 0, 2, 1,
   2, 2, 0, 0, 0, 0, 4, 2, 2, 0, 1,
   2, 8, 3, 4, 5, 8, 5, 5, 7, 1, 2,
   0, 2, 2, 2, 1, 2, 3, 0, 2, 3, 3,
   1, 3, 4, 2, 6, 4, 5, 5, 6, 6, 4,
   0, 1, 3, 3, 1, 1, 5, 3, 3, 6, 3,
   7, 3, 6, 3, 7, 6, 3, 3, 9, 6, 6,
   5, 5, 1, 4, 5, 3 };
  
  int choice=0;
  int year=0;
  int nlosses=0;
  int nwins=0;
  
  //Start while loop as long as 6(the exit option) is not selected
  while (choice!=6){  
    cout<<"1: display the record for a given year."<<endl;
    cout<<"2: display years with at least 'n' losses."<<endl;
    cout<<"3: display years with at least 'n' wins."<<endl;
    cout<<"4: display years they won as many times as they lost."<<endl;
    cout<<"5: display years there were more losses than wins."<<endl;
    cout<<"6: exit"<<endl;
  
    cout<<"Enter your choice: ";
    cin>>choice;

    //Display the record for a given year
    if (choice==1){ 
  
    cout<<"Enter the year: ";
    cin>>year;
   
    cout<<"Wins: "<<wins[year-1900]<<endl;
    cout<<"Losses: "<<losses[year-1900]<<endl; 
    }
    
    //Display years with at least 'n' losses
    if (choice==2){
      cout<<"Enter the minimum losses: ";
      cin>>nlosses;
      for (int i=0;i<=115;i++){
        if (losses[i]>=nlosses){
          int add=i+1900;
          cout<<add<<" "<<endl;
        }
      }
    }
    
    //display years with at least 'n' wins
    if (choice==3){                              
      cout<<"Enter the minimum wins: ";
      cin>>nwins;
      for (int i=0;i<=115;i++){
        if (wins[i]>=nwins){
          int add=i+1900;
          cout<<add<<" "<<endl; 
        }
      }
    }
    
    //display years they won as many times as they lost  
    if (choice==4){
      for (int i=0;i<=115;i++){
        if (wins[i]==losses[i]){
        int add=i+1900;  
        cout<<add<<" "<<endl;
        }
      }
    }
    
    //Display years there were more losses than wins 
    if (choice==5){
      for(int i=0;i<=115;i++){
        if(losses[i]>wins[i]){
          int add=i+1900;
          cout<<add<<" "<<endl;
        }       
      }
    }       
  }
}          
