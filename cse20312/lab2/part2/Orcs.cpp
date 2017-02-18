#include "Beings.h"		//include base class header 
#include "Orcs.h"		//derived (this) class header

#include <string>
#include <iostream>

using namespace std;

//constructor for the undergraduate class
//NOTE:  we need to call the constructor of the base class using
//member initialization list syntax; otherwise, we will need to use
//set functions.

Orcs::Orcs(string name, string skill, string kingdom): Beings(name, skill, kingdom){		//constructor in the member intitialization list syntax form
}
//print function 
void Orcs::print(){
	cout<<"Orc Name: "<<getName()<<endl;			//Display orc name
  cout<<"Skill: "<<getSkill()<<endl;	//display orc skill
	cout<<"Kingdom: "<<getKingdom()<<endl;	//display orc kingdom
	cout <<"Quote: Find the halflings!! Argh! Find the halflings!" <<endl;		//a quote unique to the orc class
	cout<<endl;
}


