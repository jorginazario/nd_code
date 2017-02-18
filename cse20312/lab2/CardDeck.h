#include <iostream>
#include <cstdlib> //for rand function
#include <ctime> //for rand function
using namespace std;

class CardDeck{
	friend ostream& operator<< (ostream &, CardDeck &);		//This allows us to overload the output operator
	public:
		//Constructor
		CardDeck(int=52);

		//Deconstructor
		~CardDeck();

		//Utility functions
		int getSize();
		void shuffle();

		
	private:
		//Private Members
		int * deck;
		int deckSize;
		
};

