// reverse.cpp
// prints a line in reverse order
#include <iostream>
#include <cstring>
using namespace std;

void disp_rvrs(char *);   // using a loop, and indexing on the char array
void disp_rvrs2(char *);  // using a loop, and a pointer
void disp_rvrs3(char *);  // using recursion, and a pointer

int main()
{
  char theline[30];

  cout << "enter a line: ";
  cin.getline(theline, 30);

  disp_rvrs(theline);
  cout << endl;

  disp_rvrs2(theline);
  cout << endl;

  disp_rvrs3(theline);
  cout << endl;

  return 0;
}

void disp_rvrs(char *line)
{
  for (int i = strlen(line)-1; i >= 0; i--) {
    cout << line[i];
  }
}

void disp_rvrs2(char *line)
{
  char *p = line + strlen(line);
  while (p != line) {
    p--;
    cout << *p;
  }
}

void disp_rvrs3(char *p)
{
  if (*p == 0) return;
  disp_rvrs3(p+1);
  cout << *p;
}

