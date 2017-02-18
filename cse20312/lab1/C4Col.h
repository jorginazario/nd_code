//Interface for C4Col class

#ifndef C4COL_H
#define C4COL_H

class C4Col {
	public:
		//Constructors
		C4Col();
		C4Col(char);
		//Deconstrucors
		~C4Col();
		
		//Member functions
		int isFull();
		char getDisc(int);
		int getMaxDiscs();
		void addDisc(char, int &);

	private:
		//Private members
		int currentDiscs, maxDiscs;
		char *col;
};
#endif
		
