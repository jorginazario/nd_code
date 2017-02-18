/* Jorge Nazario, humans.h
2/5/2017

This is the interface for a human derived class. This is an inheritance exmaple derived class for Lord of the Rings species.

*/

#ifndef HUMAN_H
#define HUMAN_H

#include "Beings.h"	//include our derived class interface 
#include <string>		//include string library

class Humans : public Beings{		//derived class inherits from base class
	public:
		Humans(string="empty", string="empty", string="empty");  // constructor);
		virtual void print();	//virtual function (the base class does not have this function)
	private:
		string lifeLength;	//data unique to Men in Lord of the Rings
};
#endif
