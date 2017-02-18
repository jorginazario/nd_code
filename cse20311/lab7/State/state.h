//Interface for State Class
#include <string>
using namespace std;

class State {

public:
	State();
	State(string, string, string, int, int, int);
	~State();
	void setStateAbbreviation(string);
        void setStateName(string);
	void setStateCapital(string);
	void setStatePopulation(int);
        void setYear(int);
	void setStateCongress(int);
        string getStateAbbreviation();
        string getStateName();
	string getStateCapital();
        int getStatePopulation();
	int getYear();
	int getStateCongress();
	
private:
	string StateAbbreviation;
	string StateName;
	string StateCapital;	
	int StatePopulation;
	int StateCongress;
	int Year;
};

