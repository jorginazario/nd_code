C4game: C4main.o C4Col.o C4Board.o
	g++ -o C4game C4main.cpp C4Col.o C4Board.o

C4main.o: C4main.cpp 
	g++ -c C4main.cpp

C4Col.o: C4Col.cpp C4Col.h
	g++ -c C4Col.cpp

C4Board.o: C4Board.cpp C4Board.h
	g++ -c C4Board.cpp

clean:
	rm C4game *.o C4game
