#pragma once
#include "Automaton.h"
class RightParen :
	public Automaton
{
private:
	int readings = 0; //number of characters read by this machine
public:
	RightParen();
	~RightParen();
	int getReadings();
	bool read(int it, const vector <char>& input_file);
};

