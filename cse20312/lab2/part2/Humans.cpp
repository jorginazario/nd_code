#include "Beings.h"			//include base class header
#include "Humans.h"		//derived (this) class header

#include <string>
#include <iostream>
using namespace std;

// constructor for the humans class
// We need to call the constructor of the base class using
// [[member initialization list syntax]]; otherwise, we will need to use
// set functions.

Humans::Humans(string name, string skill, string kingdom) : Beings(name, skill, kingdom) {	//this is a member initialization list syntax
}

//print function
void Humans::print() {
	cout<<"Human Name: "<<getName()<<endl;
	cout<<"Skill: "<<getSkill()<<endl;
	cout<<"Kingdom: "<<getKingdom()<<endl;
	cout <<"Quote: We fight for the survival of mankind!!" <<endl;
	cout<<endl;
}
