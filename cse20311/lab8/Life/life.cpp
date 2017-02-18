//Main Program
#include <iostream>
#include <unistd.h>
#include <cstdlib>
#include <string>
#include <fstream>
#include "lifeboard.h"


using namespace std;

int main(int argc, char *argv[]){
  char choice,q,a,n,p;
  Lifeboard board1;  
  int r, c, row, col, column, rowd, columnd;  
  ifstream ifs;
  if (argc == 1) {  // Interactive mode (if user just types the executable, nothing else)  
    while(1){
      cout<<"a : ask for coordinates where to add a new live cell (no action needed if cell is already alive)."<<endl;                     
      cout<<"r : ask for coordinates where a cell should be removed (no action needed if cell is already dead)."<<endl;
      cout<<"n : advance the simulation to the next iteration by applying the rules of the game."<<endl;
      cout<<"q : quit the program."<<endl;
      cout<<"p : play the game continuously (forever, without asking for more input; you can press control-C to stop the program)."<<endl;
      cout<<"Input your choice: ";
      cin>>choice;
      //revive a cell
      if (choice=='a'){
        cout<<"Input coordinates of new live cell: ";
        cin>>row>>column;
        board1.livecell(row, column);
        system("clear");
      cout<<"Current board: "<<endl;
      cout<<board1<<endl;  
      }
      //kill a cell
      if (choice=='r'){
        cout<<"Input coordinates of cell you wish to kill: ";
        cin>>rowd>>columnd; 
        board1.deadcell(rowd, columnd);
        system("clear");
        cout<<"Current board: "<<endl;
        cout<<board1<<endl; 
      }
      //advance the simulation to the next iteration 
      if (choice=='n'){
        cout<<"Current board: "<<endl;
        system("clear");
        board1.iteration();
        cout<<board1<<endl; 
      }     
        
      //play the game continously
      if (choice=='p'){ 
        while(1){
          system("clear");
          board1.iteration();
          cout<<board1<<endl;
          usleep(100000);
        }
      }
      if (choice=='q'){
        return 0;
      }
    }
  }
  else if (argc > 2) {  // if user types more than one name after executable
    cout << "too many names" << endl;
    return 2;
  }
  else {  // user correctly typed only one name after executable; argv[1] is that name
   ifs.open(argv[1]);
   if (!ifs){
     cout<<"Error opening file"<<endl;
     return 1;
   }
   while(!ifs.eof()){
    ifs>>choice;
    if (choice!='p'){
      ifs>>row>>col;
      board1.livecell(row,col); 
    }
    else
      while(1){
        system ("clear");
        board1.iteration();
        cout<<board1<<endl;
        usleep(100000);       
      }
    }
  }
}
