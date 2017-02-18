#include "Beings.h"		//include base class interface
#include "Humans.h"		//include derived class interface
#include "Orcs.h"			//include derived class interface
#include <iostream>

using namespace std;

int main(){
	 
	Orcs aorc("Lurtz", "Bow", "Mordor");				//instantiate an object of one of the derived classes
	Humans ahum("Aragorn", "Sword", "Gondor");	//instantiate an object of one of the derived classes
	
	Humans * Hderived_ptr=&ahum;	//base and derived class is abstract
	Orcs * Oderived_ptr= &aorc;		//base and derived class is abstract
	
	Hderived_ptr->print();		//call the virtual print function with the pointer
	Oderived_ptr->print();		//call the virtual print function with the pointer
		
		
}
