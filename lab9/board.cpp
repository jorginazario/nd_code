// Juan Pablo Borrero & Jorge Nazario
// CSE 20311
// Lab 9
//
// Class Implementation

#include <iostream>
using namespace std;
#include <cmath>
#include "board.h"

#define SIZER 15
#define SIZEC 15

Board::Board(){
        for (int i = 0; i < SIZER; i++) {
                for (int j = 0; j < SIZEC; j++) {
                                arr[i][j]='.';
                }
        }
}

Board::Board(char a[SIZER][SIZEC]){
        arr[SIZER][SIZEC]=a[SIZER][SIZEC];
}


Board::~Board(){}

//get-set methods
char Board::getBoard(){
        return arr[SIZER][SIZEC];
}

void Board::setBoard(char a[SIZER][SIZEC]){
        arr[SIZER][SIZEC]=a[SIZER][SIZEC];
}


//Utility functions

void Board::insertFirstWord(string s, int &r, int &c, string &dir){ // To insert the first word in the middle of the Board
	int pos, j = 0;
	int wlength = s.length();

	pos = (SIZEC - wlength)/2;
	s.c_str();	
	for(int i = pos; i < wlength + pos; i++, j++){
		arr[7][i] = s[j];
	}
	r=7;
	c=pos;
	dir="Right";	
}

bool Board::insertBoard(string s, int &r, int &c, string &dir){ // To insert words into Board. Insert variables row and column passing by reference
	bool possible = false;
	int p = 0;
	char tempBoard[SIZER][SIZEC];
	// Copy Board to the temporary board
	 for(int p =0; p < SIZER; p++){
		for(int q = 0; q < SIZEC; q++){
			tempBoard[p][q]=arr[p][q];
		}
        }

	s.c_str();
	for(int i = 0; i <SIZER; i++){ // Navigate through rows
		for(int j = 0; j<SIZEC; j++){ // Navigate through columns
			if(tempBoard[i][j] != '.'){ //Check for characters in board
				for(int k = 0; k < s.size(); k++){ //Navigate through our string
					if(s[k] == tempBoard[i][j]){ // Match between character of board and char of s
						bool a = true;
						if(tempBoard[i][j+1] != '.' || tempBoard[i][j-1] != '.'){ // match is a horizontal word
							if((i-k) >= 0 && (i+s.size()-k) < SIZER){ // check for boundaries	
								for (int q = j-1; q<=j+1; q++){ // Check borders are clear (spaces between w)
									for(int l = i-k; l < i+s.size()-k; l++){ // Check space is clear
										if(tempBoard[l][q]!='.' && i != l){ 	
											a = false;		
										}
									}
								}
								if(tempBoard[i-k-1][j]!= '.' || tempBoard[i+s.size()-k][j] != '.'){
									a = false;	
								}
							}
							else {
								a = false;
							}
							//After checking that word can be inserted vertically, ie. a = true
							if (a == true){
								for(int l = i-k; l < i+s.size()-k; l++, p++){ //go up (rows) the amount char before the match
									arr[l][j]=s[p]; //place the first char in the location 
								}	
								r = i - k; // Return coordinate for clues
								c = j;								
								dir = "Down";
								return possible = true;
							}
							
						}
						else if(tempBoard[i-1][j] != '.' || tempBoard[i+1][j] != '.'){ // match is a vertical word
							if((j-k) >= 0 && (j+s.size()-k) < SIZEC){ // check for boundaries
								for(int q = i-1; q<=i+1; q++){
									for(int l = j-k; l < j+s.size()-k; l++){ // check space is clear
										if(tempBoard[q][l] != '.' && l != j)
											a = false;
									}
								}
								if(tempBoard[i][j-k-1] != '.' || tempBoard[i][j+s.size()-k] != '.')
									a = false;
							}
							else
								a = false;
							// After checking that the word can be inserted horizontally, ie. a = true	
							if(a == true){	
								for(int l = j-k; l < j+s.size()-k; l++, p++){
									arr[i][l]=s[p];
								}
								r=i; // Return coordinates for clues
								c=j-k;							
								dir="Right";
								return possible = true;
							}
						}
					}
				}				
			}
		}	
	}
	return possible;
}


void Board::encodeBoard(Board a1){ // To enconde Board
	for(int i = 0; i < SIZER; i++){
		for(int j = 0; j < SIZEC; j++){
			arr[i][j]='#';
			if(a1.arr[i][j] != '.')
				arr[i][j] = ' ';
		}
	}
}

//Overload of << operator
ostream& operator<< (ostream &out, Board &board){
        for (int i = 0; i<SIZEC+2; i++){
                out << "*";
        }
        out << endl;

        for (int k = 0; k<SIZER; k++){
                out << "*";
                for (int j = 0; j<SIZEC; j++){
                        out << board.arr[k][j];
                }
                out << "*";
                out << endl;
        }

        for (int l = 0; l<SIZEC+2; l++){
                out << "*";
        }
        out << endl;
        return out;
}

