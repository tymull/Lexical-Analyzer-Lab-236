#pragma once
#include "Automaton.h"
class MyString :
	public Automaton
{
private:
	int readings = 0; //number of characters read by this machine
public:
	MyString();
	~MyString();
	int getReadings();
	bool endString(int it, const vector <char>& input_file);
	bool isStuff(int it, const vector <char>& input_file);
	bool read(int it, const vector <char>& input_file);
};

