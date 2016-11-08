#pragma once
#include "Automaton.h"
class Colon :
	public Automaton
{
private:
	int readings = 0; //number of characters read by this machine
public:
	Colon();
	~Colon();
	int getReadings();
	bool read(int it, const vector <char>& input_file);
};
//this is in Lex2

