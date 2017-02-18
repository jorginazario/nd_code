//Class Implementation
#include <iostream>
using namespace std;
#include "lifeboard.h" //prototype
#define ROWS 41
#define COL 41

Lifeboard::Lifeboard(){
  for (int i=0; i<ROWS;i++){
    for (int j=0; j<COL; j++){
      cells[i][j]=' ';
    }
  }
}

Lifeboard::~Lifeboard()
  {}

void Lifeboard::deadcell(int r, int c)
  {cells[r][c]=' ';}

void Lifeboard::livecell(int r, int c)
  {cells[r][c]='x';}

void Lifeboard::iteration(){
   int nei=0; 
   for (int r=0; r<ROWS+1; r++){
     for (int c=0; c<COL+1; c++){        
       if (cells[r-1][c]=='x'){
         nei++;
       }
       if (cells[r+1][c]=='x'){
         nei++;
       }
       if (cells[r][c-1]=='x'){
         nei++;
       }
       if (cells[r][c+1]=='x'){
         nei++;
       }
       if (cells[r+1][c+1]=='x'){
         nei++;
       }
       if (cells[r-1][c-1]=='x'){ 
         nei++; 
       }
       if (cells[r+1][c-1]=='x'){
         nei++;
       }
       if (cells[r-1][c+1]=='x'){
         nei++;
       }
       
       if (nei==3){
         temp[r][c]='x';
       }
       else if (cells[r][c]=='x' && nei==2){
         temp[r][c]='x'; 
       }
       else 
         {temp[r][c]=' ';}

       nei=0;
     }
   }
   for (int i=1; i<ROWS+1;i++){
     for (int j=1;j<COL+1;j++){
       cells[i][j]=temp[i][j];
     }
   }       
}
ostream& operator<<(ostream &s, Lifeboard &board1){
  for (int i=0; i<COL+2; i++){
    s<<"#";
  }
  s<<endl;

  for (int i=0; i<ROWS; i++){
    s<<"#";
    for (int j=0; j<COL; j++){
      s<<board1.cells[i][j];
    }
    s<<"#";
    s<<endl;
  }
  for (int i=0; i<COL+2; i++){
    s<<"#";
  }
  s<<endl;  
  return s;
}
