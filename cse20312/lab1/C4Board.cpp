//C4Board Class Implementation
#include <iostream>
using namespace std;
#include "C4Board.h"
#include "C4Col.h"

//Constructor
C4Board::C4Board(){
	int numCols=7;
	board = new C4Col[50];
}

//Deconstructor
C4Board::~C4Board(){
	delete [] board;
}

//Add extra fromatting including | between cols, a num indicating which colum is
void C4Board::display(){
	int numCols=7;
	for (int i=board[0].getMaxDiscs()-1; i>=0;i--){
		for (int j=0; j<numCols; j++){
			cout<<board[j].getDisc(i)<<" |";
		}
		cout<<endl;
	}
	cout<<" ";
	for (int i=0; i<7; i++){
		cout<<i+1<<"  ";
	}
}

//Play function (basically runs the entire program)
void C4Board::play(){
	int currentPlayer=1;
	char charPlayer=(currentPlayer==1)? 'X' : 'O';
	int turn=0;
	int choice;
	cout<<"Welcome the game of Connect four!"<<endl;
	display();
	
	//Keep running program until there is a winner or until the user types -1
	while (choice!=-1){			
    		cout<<endl;
		currentPlayer=(turn%2)+1;
		charPlayer=(currentPlayer==1)? 'X' : 'O';
		cout<<"Player "<<currentPlayer<<"'s turn. Choose a column:"<<endl; 
		cin>>choice;
		while (choice>7){
			cin>>choice;
		}
		//Add a 'X' to the board in the column the user chose
		if (currentPlayer==1){
			board[choice-1].addDisc('X', turn);
			turn++;	
			display();
			//Verify if this last piece was the winner piece
                        if (checkWin(charPlayer, choice-1)){
                        	cout<<"Congrats Player "<<currentPlayer<<" you win!!!"<<endl;
				break;
			}

						
		}
		//Add a 'O' to the board in the column the user chose
		else if (currentPlayer==2){
			board[choice-1].addDisc('O', turn);
			turn++;	
			display();
                	//Verify if this last piece was the winner piece
                	if (checkWin(charPlayer, choice-1)){
                		cout<<"Congrats Player "<<currentPlayer<<" you win!!!"<<endl;
				break;
			}

		}
		//display();
		//Verify if this last piece was the winner piece
		if (checkWin(charPlayer, choice-1)){
			cout<<"Congrats Player "<<currentPlayer<<" you win!!!"<<endl;
     			break;
    		}	
	}
}

//Function checks if the inserted disc is the last piece for a combination of 4
bool C4Board::checkWin(char player, int col){
	int totalDiscs = 0;
	int row = 0;                             
	for (int i = board[0].getMaxDiscs() - 1; i>=0; i--){
		if(board[col].getDisc(i) != ' '){
			row = i;
			break;
		}
	}
	//Checks for horizontal C4
	for (int i = -3, totalDiscs = 0; i < 4; i++){
	 	 // check within boundaries
   		if (col+i >= 0 && col+i <= 6){
    			//check if match                        
      			if (board[col+i].getDisc(row) == player)
        			totalDiscs++; //add to the counter how many discs together
      			else
        			totalDiscs = 0;
      			if(totalDiscs == 4)
        			return true;
    		}
  	}

  	//Checks for vertical C4
  	for (int i = -3, totalDiscs = 0; i < 4; i++){
  		// check within boundaries
    		if (row+i >= 0 && row+i <= 5){     
    			//check if match                     
      			if (board[col].getDisc(row+i) == player)                
        			totalDiscs++; //add to the counter how many discs together
     		 	else
        			totalDiscs = 0;
      			if (totalDiscs == 4)
        			return true;
    		}
  	}

  	//Checks for diagonal C4
  	for (int i = -3, j = -3, totalDiscs = 0; i < 4; i++, j++){
  		// check within boundaries
    		if (col+j >= 0 && col+j <= 6 && row+i >= 0 && row+i <= 5){
     			//check if match 
      			if (board[col+j].getDisc(row+i) == player)    
        			totalDiscs++;
      			else
        			totalDiscs = 0;
      			if (totalDiscs == 4)
        			return true;
    		}
  	}

  	//Checks for diagonal C4
  	for (int i = 3, j = -3, totalDiscs = 0; j < 4; i--, j++){
  		// check within boundaries
    		if (col+j >= 0 && col+j <= 6 && row+i >= 0 && row+i <= 5){
    			//check if match 
      			if (board[col+j].getDisc(row+i) == player)
        			totalDiscs++;
      			else
        			totalDiscs = 0;
      			if (totalDiscs == 4)
        			return true;
    		}
  	}

  	return false;
}
