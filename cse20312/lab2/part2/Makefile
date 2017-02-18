all:    main

main: main.o Beings.o Humans.o Orcs.o
	g++ -std=c++11 main.o Beings.o Humans.o Orcs.o -o main
main.o: main.cpp
	g++ -std=c++11 -c main.cpp
Beings.o: Beings.cpp
	g++ -std=c++11 -c Beings.cpp
Humans.o: Humans.cpp
	g++ -std=c++11 -c Humans.cpp
Orcs.o: Orcs.cpp
	g++ -std=c++11 -c Orcs.cpp
clean:
	rm -f *.o main
