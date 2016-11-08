#include "Period.h"


Period::Period()
{
}


Period::~Period()
{
}

int Period::getReadings()
{
	return readings;
}

bool Period::read(int it, const vector <char>& input_file)
{
	if (getChar(it, input_file) == '.')
	{
		readings++; //indicates that it successfully read
		return true;
	}
	else
	{
		return false;
	}
}
