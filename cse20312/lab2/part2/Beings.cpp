/* Jorge Nazario, Beings.cpp
2/5/2017

Implementation of the base class functions.  We can instantiate a copy if we like without a problem (and do in our main.cpp). If we want to disallow instantiating a class we include at least one "pure virtual" function.  We'll cover this more in detail next Monday
*/

#include "Beings.h"
#include <iostream>

using namespace std;

//constructor for Beings class
Beings::Beings(string name, string skill, string kingdom) {

	Name = name;			//set values
	Skill = skill;		//set values
	Kingdom = kingdom;	//set values
}

//set functions
void Beings::setName(const string val) {
	Name = val;
}

void Beings::setSkill(const string val) {
	Skill=val;
}

void Beings::setKingdom(const string val) {
	Kingdom=val;
}
//get functions
string Beings::getName(){
	return Name;
}

string Beings::getSkill(){
	return Skill;
}

string Beings::getKingdom(){
	return Kingdom;
}

