#include <iostream>
using namespace std;

#define SIZER 15
#define SIZEC 15

class Board{

        friend ostream& operator<< (ostream &, Board &);

public:
        Board();
        Board(char a[][SIZEC]);
        ~Board();

        char getBoard();
        void setBoard(char a[][SIZEC]);

//Utility methods
	bool insertBoard(string, int &, int &, string &);	
	void insertFirstWord(string, int &, int &, string &);
	void encodeBoard(Board);

private:
        char arr[SIZER][SIZEC];
};
