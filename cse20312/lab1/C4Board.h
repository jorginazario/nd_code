//C4Board interface
#include "C4Col.h"
#ifndef C4BOARD_H
#define C4BOARD_H


class C4Board{
	public:
		//Constructors
		C4Board();
		C4Board(int);
		
		//Deconstructor
		~C4Board();
		
		//Member Functions
		void display();
		void play();
		bool checkWin(char, int);
		
	private:
		//private member
		C4Col *board; 
		
		
};
#endif
