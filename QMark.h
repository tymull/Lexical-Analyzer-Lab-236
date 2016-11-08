#pragma once
#include "Automaton.h"
class QMark :
	public Automaton
{
private:
	int readings = 0; //number of characters read by this machine
public:
	QMark();
	~QMark();
	int getReadings();
	bool read(int it, const vector <char>& input_file);
};

