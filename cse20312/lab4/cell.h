//cell.h class protoype
#include <iostream>
using namespace std;


class cell{
	public:
		cell();
		~cell();
		addPossible();	//add possibilities to my vector member
		hardCode();	//hard code the solution once it is found
		check();	//check all the possibilities (row, column, block)
		singleton();	//compares each cell's list of possible numbers and identifies if there is opportunitiy to hard code one
		
	private:
		int member;	//this is the cell number solution
		vector<int> possible;	//every cell will have a list of possible numbers
}

