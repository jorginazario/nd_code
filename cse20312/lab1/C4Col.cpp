//Implementation for C4Col class
#include <iostream>
#include "C4Col.h"

using namespace std;
//Constructor
C4Col::C4Col(){
	currentDiscs=0;
        maxDiscs=6;
	
	col = new char[ maxDiscs ];
	for (int i=0; i<maxDiscs; i++){
		col[i]=' ';
	}
}

//Deconstructor
C4Col::~C4Col(){
	delete [] col;
}

//Function verifies if the column is full
int C4Col::isFull(){
	if (currentDiscs==maxDiscs){
		return 1;
	}
	else return 0;
}

//Function returns the value of the private member disc
char C4Col::getDisc(int pos){
	return col[pos];	
	if (col[pos]>6 || col[pos]<0){
		return 0; //out of bounds
	}
}

//Return maximum disc limit
int C4Col::getMaxDiscs(){
	return maxDiscs;
}

//Function adds a disc to the column and warns if it is already full
void  C4Col::addDisc(char newDisc, int &turn){
	if (isFull()){
		cout<<"This column is full!!! Try another one."<<endl;
		turn--;
	}
	else {
		col[currentDiscs++]=newDisc;
	}					
}

