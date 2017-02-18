#include <iostream>
#include <cstdlib> //for rand function
#include <ctime> //for rand function
using namespace std;

class CardDeck{
	friend ostream& operator<< (ostream &, CardDeck &);
	public:
		//Constructor
		CardDeck(int=52);

		//Deconstructor
		~CardDeck();

		//Utility functions
		int getSize();
		void shuffle();
		void Deal();
	private:
		//Private members
		int * deck;
		int deckSize;
		int yWin;
		int dWin;
		int posit;
		
};

