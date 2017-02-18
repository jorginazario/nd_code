#include <iostream>
#include <string>
#include <fstream>
#include <vector>
using namespace std;

#include "state.h"
//Initialize functions
void displayall(vector<State> &s);
void yearstates(vector<State> &s, int);
void stateinfo(vector<State> &s, string);
void bigpop(vector<State> &s);

int main(){
  //initilize variables
  ifstream ifs;
  string infilename;
  string StateName, StateAbbreviation, StateCapital, Year_str, StateCongress_str, StatePopulation_str, statename, currentst;
  int Year, StateCongress, StatePopulation, choice, yearchoice;
  vector<State> states;
  State currentstate;
  //input file
  cout << "enter data file name: ";
  cin >> infilename;
  ifs.open(infilename);
  if (!ifs) {
    cout << "bad file name: " << infilename << endl;
    return 1;
  } 

  char c = ifs.peek();
  while(c != EOF) {
    getline(ifs, StateAbbreviation , ',');
    getline(ifs, StateName , ',');
    getline(ifs, StateCapital , ',');
    getline(ifs, StatePopulation_str , ',');
    getline(ifs, Year_str , ',');
    getline(ifs, StateCongress_str);

    //Change the variable strings into integers
    StatePopulation=stoi(StatePopulation_str);
    Year = stoi(Year_str);
    StateCongress=stoi(StateCongress_str);

    //push back each state into the vector 
    currentstate=State(StateAbbreviation, StateName, StateCapital, StatePopulation, Year, StateCongress);
    states.push_back(currentstate);
    c = ifs.peek();
  }
  //Menu
  while (choice!=5){
    cout<<"1. Display all states"<<endl;
    cout<<"2. Look for all the states that were inaugurated a certain year"<<endl;   
    cout<<"3. Display all the information on a single state"<<endl;
    cout<<"4. Display state with largest population"<<endl; 
    cout<<"5. Quit"<<endl;
    cout<<"Choose your option: ";
    cin>>choice;
    //Display all states
    if (choice==1){
      displayall(states);
    }
    //Display states in the input year
    if (choice==2){
      cout<<"Input year: ";
      cin>>yearchoice;
      yearstates(states, yearchoice); 
    }
    //Show all info on a given state
    if(choice==3){
      cout<<"Input state name: ";
      cin>>statename;
      stateinfo(states, statename);
    }
    //find state with biggest population
    if (choice==4){
      bigpop(states);
    }
    //quit
    if (choice==5){
      return 0;
    }
  }
}
//display all states
void displayall(vector<State> &s){
  for (auto it = s.begin(); it != s.end(); ++it) {
    cout <<"State Name: "<< it->getStateName()<<endl;
    cout <<"State Abbreviation: "<< it->getStateAbbreviation() << endl;
    cout <<"Year Inaugurated: "<< it->getYear() << endl;
    cout <<"State Congress: "<< it->getStateCongress() <<endl;
    cout <<"State Capital: "<< it->getStateCapital()<<endl;
    cout <<"State Population: "<< it->getStatePopulation()<<endl;
    cout <<" "<<endl;
  }
}
//Display state inaugurated in a given year
void yearstates(vector<State> &s, int yearchoice){
  for (auto it=s.begin(); it!=s.end();++it){
    if (it->getYear() ==yearchoice){
      cout<<it->getStateName()<<endl;
    }
    else 
      cout<<"Not a single state was inagurated that year"<<endl;
  }
}
//Show all info of a given state
void stateinfo(vector<State> &s, string statename){
  for(auto it=s.begin(); it!=s.end(); ++it){
    if (it->getStateName()==statename){    
      cout <<"State Name: "<< it->getStateName()<<endl;
      cout <<"State Abbreviation: "<< it->getStateAbbreviation()<<endl;
      cout <<"Year Inaugurated: "<< it->getYear() << endl;
      cout <<"State Congress: "<< it->getStateCongress() <<endl;
      cout <<"State Capital: "<< it->getStateCapital()<<endl;
      cout <<"State Population: "<< it->getStatePopulation()<<endl;
      cout <<" "<<endl;
      break;
    }
  } 
    cout<<"Invalid input"<<endl;
}
//Display state with biggest population
void bigpop(vector<State> &s){
  int currentpop=0;
  string currentst;
  for (auto it=s.begin(); it!=s.end();++it){
    if (it->getStatePopulation()>=currentpop){
      currentst=it->getStateName();
      currentpop=it->getStatePopulation();      
    }
  }
  cout<<currentst<<" Population: "<<currentpop<<endl;
  cout<<" "<<endl;
}
    
