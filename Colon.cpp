#include "Colon.h"


Colon::Colon()
{
}


Colon::~Colon()
{
}

int Colon::getReadings()
{
	return readings;
}

bool Colon::read(int it, const vector <char>& input_file)
{
	if (getChar(it, input_file) == ':')
	{
		readings++; //indicates that it successfully read
		return true;
	}
	else
	{
		return false;
	}
}

