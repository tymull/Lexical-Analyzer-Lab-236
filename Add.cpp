#include "Add.h"


Add::Add()
{
}


Add::~Add()
{
}

int Add::getReadings()
{
	return readings;
}

bool Add::read(int it, const vector <char>& input_file)
{
	if (getChar(it, input_file) == '+')
	{
		readings++; //indicates that it successfully read
		return true;
	}
	else
	{
		return false;
	}
}
