#include "WhiteSpace.h"


WhiteSpace::WhiteSpace()//(vector <char> input_file)
//:Automaton(input_file)
{
	// Nothing to do
//	this->input_file = input_file;
}


WhiteSpace::~WhiteSpace()
{
}

int WhiteSpace::getReadings()
{
	return readings;
}

bool WhiteSpace::read(int it, const vector<char>& input_file)
{
	if (isblank(getChar(it, input_file)))
	{
		readings++; //indicates that it successfully read
		return true;
	}
	else
	{
		return false;
	}
}
