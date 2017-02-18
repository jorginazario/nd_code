blackjack: bjmain.o CardDeck.o
	g++ -o blackjack bjmain.cpp CardDeck.o
bjmain.o: bjmain.cpp
	g++ -c bjmain.cpp
CardDeck.o: CardDeck.cpp CardDeck.h
	g++ -c CardDeck.cpp
clean:
	rm blackjack *.o blackjack


