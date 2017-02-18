#include "CardDeck.h"
#include <cstdlib> //rand function lib
#include <ctime> //rand function lib
using namespace std;

//Constructor
CardDeck::CardDeck(int n){
	srand(time(NULL));				//Change the seed of randomness
	deck = new int[n];				//dynamically allocated array of n integers (for data hiding)
	deckSize=n;
	for (int i=0; i<deckSize; i++){			//populate the deck with numbers from 1-52
		deck[i]=i+1;
	}
}
//Deconstructor
CardDeck::~CardDeck(){
	delete [] deck;
}

//Member functions 
int CardDeck::getSize(){				//returns the size of the deck
	return deckSize;
}
void CardDeck::shuffle(){				//This function shuffles the deck by swapping two random cards in the deck
	int num;
	int temp;
	for (int i=0; i<deckSize;i++){
		num=rand()%deckSize;			//Random number that ranges from 0-(deckSize-1)
		temp=deck[i];				//Save the element that is about to be overwritten
		deck[i]=deck[num];
		deck[num]=temp;				//Overwrite the card that is doubled with the temp that was deleted previously
	}
}
ostream&  operator<<(ostream &s, CardDeck &myDeck){	//overloading of the output operator (to cout<<CardDeck;)
	
	for (int i=0; i<myDeck.deckSize; i++){		//for loop that goes over the deck array and prints elements
		if (i<myDeck.deckSize-1)		//check if we are at the last element of the array; if so go to the else statment and print endl
			s<<myDeck.deck[i]<<", ";
		else 
			s<<myDeck.deck[i]<<endl;
	}
	return s;	
}
