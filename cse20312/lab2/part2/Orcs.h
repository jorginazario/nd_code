#ifndef ORCS_H
#define ORCS_H
#include "Beings.h"	//include base class interface
#include <string>		//include string lilbrary
using namespace std;

class Orcs : public Beings{	//derived orcs class inherits from Beings
        public:
                Orcs(string="empty", string="empty", string="empty");         //constructor
                virtual void print();		//virtual print function (the base class does not have this function)

        private:
                string Type;		//data unique to Orcs either 
};
#endif
