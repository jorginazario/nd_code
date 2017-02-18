//Implementation
#include <iostream>
using namespace std;
#define ROWS 41
#define COL 41

class Lifeboard {
friend ostream& operator<<(ostream &, Lifeboard&);
public:
Lifeboard();
//Lifeboard(char board2[][COL]);
~Lifeboard();
void livecell(int, int);
void deadcell(int, int);
//void update(Lifeboard);
void iteration();
//void print();

private:
char cells[ROWS][COL];
char temp[ROWS][COL];
};
