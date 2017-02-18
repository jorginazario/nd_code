//Class Implementation for the State Class
#include "state.h"

State::State() 
	{}

State::State(string ab, string nm, string cp, int pop, int yr, int cg)
	{StateAbbreviation=ab; StateName=nm; StateCapital=cp; StatePopulation=pop; Year=yr; StateCongress=cg;}

State::~State() 
	{}

void State::setStateAbbreviation(string ab)
	{StateAbbreviation=ab;}

void State::setStateName(string nm)
	{StateName=nm;}

void State::setStateCapital(string cp)
	{StateCapital=cp;}

void State::setStatePopulation(int pop)
	{StatePopulation=pop;}

void State::setYear(int yr)
	{Year=yr;}

void State::setStateCongress(int cg)
	{StateCongress=cg;}

string State::getStateAbbreviation()
	{return StateAbbreviation;}

string State::getStateName()
	{return StateName;}

string State::getStateCapital()
	{return StateCapital;}

int State::getStatePopulation()
	{return StatePopulation;}

int State::getYear()
	{return Year;}

int State::getStateCongress()
	{return StateCongress;}

