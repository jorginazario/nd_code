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
void CardDeck::Deal(){
	cout<<"Welcome to the game of Black Jack!!!"<<endl;		//Initialization of variables
	bool keepPlaying=true;
	bool newDeck=true;
	char kp;
	int choice=0;
	int posit=0;
	int dWin=0;
	int yWin=0;
	int Drand, Yrand, Dcard, D2card, Ycard, Y2card;
	
	//Stop playing when the bool is false
	while (keepPlaying){
		Dcard=0;	//initialize Dealer card sum as 0
		Ycard=0;	//initialize Dealer card sum as 0
		if (newDeck==true || posit>=47){	//if the deck is in its last 15 cards shuffle the deck and start from the beginning
			shuffle();	//shuffle function shuffles the deck by randomly placing int's 1-52 in the 52 index array
			newDeck=false;	
			posit=0;	//we start at index zero of the deck private member array and move up to choose different cards
		}
		Dcard=(deck[posit])%13+2;		//change dealer card to a number of 1-14 
		posit++;				//increment array index by one each time we have used the card in that index already
		if (Dcard>11){	//convert numbers 12,13,14 to 10's representing J,Q,K
			Dcard=10;
		}
		Ycard=(deck[posit])%13+2;		//user (your) card 1-14
		posit++;				//increment array index by one
		if (Ycard>11){	//convert numbers 12,13,14 to 10's representing J,Q,K
			Ycard=10;
		}
		
		//Player Interface Display
		cout<<"Dealer Score: "<<dWin<<"********"<<"Your score: "<<yWin<<endl;	//display score
		cout<<"************************************************"<<endl;				//barrier to help guide the user
		cout<<"Dealer hand: "<<Dcard<<endl;																		//dealer hand (sum of cards)
		cout<<"Your hand: "<<Ycard<<endl;    																	//your hand (sum of cards)
		cout<<"Options: '1' to hit or '2' to stay ('3' to quit)"<<endl;				//options
		cin>>choice;	//read player choice
		cout<<endl;
		
		
		while (choice==1){	//this while loop is used for when the player 'hits' and wants to add another card
			Y2card=(deck[posit])%13+2;		//deal second card
			posit++;		//move up in index to not repeat card 
			if (Y2card>11){			//check if second card drawn is over 11 to convert it to 10
				Y2card=10;
			}
			Ycard=Ycard+Y2card;		//add both (all) cards
			Y2card=0;
			if (Ycard>21){	//if you go over 21 you lose
				cout<<"You went over!"<<endl;
				dWin++;
				choice=0;
				cout<<"Dealer Score: "<<dWin<<"********"<<"Your score: "<<yWin<<endl;
				cout<<"************************************************"<<endl;
				cout<<"Dealer hand: "<<Dcard<<endl;
				cout<<"Your hand: "<<Ycard<<endl;
				cout<<"Continue playing? y/n"<<endl;	//give the player the option to stop playing after each hand
				cin>>kp;
				if (kp=='y'){
					break; //CHANGE
				}
				else if (kp =='n'){
					cout<<"Thank you for playing!!!"<<endl;
					keepPlaying=false;
					break;
       	}
       }
       	//Display game interface
				cout<<"Dealer Score: "<<dWin<<"********"<<"Your score: "<<yWin<<endl; 	
				cout<<"************************************************"<<endl;
				cout<<"Dealer hand: "<<Dcard<<endl;
				cout<<"Your hand: "<<Ycard<<endl;		
				cout<<"Options: '1' to hit or '2' to stay ('3' to quit)"<<endl;
				cin>>choice;
				cout<<endl;
		}				
		if (choice==2){	//player chooses to 'stay' with the cards he has and it is the dealers turn to grab a card if he is below 17
			while (Dcard<17){	//if the user stays, the dealer pick cards until it reaches a number 17 or higher
				D2card=(deck[posit])%13+2;		//Dealer's additional card
				posit++;		//add move up in the deck array
				if (D2card>11){                 //check if second card drawn is over 11 to convert it to 10
					D2card=10;
				}
				Dcard=Dcard+D2card;             //add both (all) cards
				D2card=0;
				cout<<"Dealer Score: "<<dWin<<"********"<<"Your score: "<<yWin<<endl;   
				cout<<"************************************************"<<endl;
				cout<<"Dealer hand: "<<Dcard<<endl;
				cout<<"Your hand: "<<Ycard<<endl;               
			}
		
			if (Dcard>21){		//if the Dealer's hand is larger than 21 he loses
				cout<<"Dealer went over! You win!"<<endl;
				yWin++;
				choice=0;
				cout<<"Continue playing? y/n"<<endl;
				cin>>kp;
				if (kp=='y'){		//ask the user if he wants to keep playing
					continue;
				}
				else if (kp =='n'){
					cout<<"Thank you for playing!!!"<<endl;
					keepPlaying=false;
					break;
				}
			}
			else if (Dcard>Ycard){		//If Dealer hand is larger than your hand, dealer wins
				cout<<"The dealer won!"<<endl;
				dWin++;
				choice=0;
				cout<<"Continue playing? y/n"<<endl;
				cin>>kp;				//ask user if he want to keep playing
				if (kp=='y'){
					continue;
				}
				else if (kp =='n'){
					cout<<"Thank you for playing!!!"<<endl;
					keepPlaying=false;
					break;
				}				
			}
			else if (Ycard>Dcard){		//If your hand is larger than dealer's hand you win
				cout<<"You win!"<<endl;
				yWin++;
				choice=0;
				cout<<"Continue playing? y/n"<<endl;
				cin>>kp;		//ask the user if he still wants to play
				if (kp=='y'){
					continue;
				}
				else if (kp =='n'){
					cout<<"Thank you for playing!!!"<<endl;
					keepPlaying=false;
					break;
				}
			}
		}			
		if (choice==3){		//quit program
			cout<<"Thank you for playing!!!"<<endl;
			keepPlaying=false;
			break;
		}
		cout<<endl;		
	}
}
