#include <iostream>
#include <vector>
#include <cstdlib>
#include <cctype>
#include <cmath>
#include <string>
#include <fstream>


using namespace std;

int main(){
  //initialize variables
  string filename, filetext;
  ifstream ifs;
  ofstream ofs;
  vector<int>numletters;
  char singlechar;
  int charnum;
  double spaces=0;
  int punctuation=0;
  int letternum;
  char letter;
  int numsum=0;
  double charsum=0;
  //create a vector with 26 zeros
  for (auto i=0; i<26;i++){
    numletters.push_back(0);
  }
  //get file that will be searched
  cout<<"Enter startup file name: ";
  cin>>filename;

  ifs.open(filename);
  if (!ifs){
    cout<<"Error opening file"<<endl;
    return 1;
  }

  cin.ignore();
  while (!ifs.eof()){
    singlechar=ifs.get();//get individual character
      //countspaces 
      if (isspace(singlechar)){
        spaces++;
      }
      //convert number from ascii value to a value from 1 to 26
      //and add up the amount of each letter
      else if (singlechar>=65 && singlechar<=90){
        singlechar=tolower(singlechar);
        singlechar=singlechar-97;
        numletters[singlechar]++;
      }
      else if (singlechar>=97 && singlechar<=122){
        singlechar=singlechar-97;
        numletters[singlechar]++;
      }
      //count punctuation
      else if (ispunct(singlechar)){
        punctuation++;
      }
  }
  cout<<spaces<<endl;
  int qu=1;
  int counter=1;

  //display the letter with the amount of times it showd up
  //display everything else
  for (auto it=numletters.begin();it<numletters.end();it++){
    letternum=qu+96;
    letter=letternum;
    cout<<letter<<": "<<*it<<"  ";
    qu++;
    if (counter>5){
      cout<<endl;
      counter=0;
    }
    counter++;
    numsum=numsum+*it;
  }
  charsum=numsum+spaces+punctuation;
  cout<<endl<<"There were "<<numsum<<" letters."<<endl;
  cout<<"There were "<<charsum<<" total characters."<<endl;
  cout<<"There were "<<spaces<<" white space characters."<<endl;

  double spaceper;
  spaceper=(spaces/charsum)*100;

  cout<<"Space percentage: "<<spaceper<<"%"<<endl;

  return 0;


}

