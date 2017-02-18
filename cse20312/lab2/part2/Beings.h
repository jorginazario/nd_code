#ifndef BEINGS_H
#define BEINGS_H

#include <string> //include string library
using namespace std;

class Beings{		//base class for all beings in Lord of the Rings
	public:
		Beings(string="empty", string="empty", string="empty");		//constructor
		void setName(const string);	//set functions
		void setSkill(const string);
		void setKingdom(const string);
		string getName();			//get functions (strings)
		string getSkill();
		string getKingdom();
		virtual void print()=0;    // print function


		
	protected: //make our data protected, not private, so inherited classes can access them directly
		//protected members
		string Name;
		string Skill;
		string Kingdom;

	
};

#endif
