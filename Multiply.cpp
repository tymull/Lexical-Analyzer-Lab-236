#include "Multiply.h"


Multiply::Multiply()
{
}


Multiply::~Multiply()
{
}

int Multiply::getReadings()
{
	return readings;
}

bool Multiply::read(int it, const vector <char>& input_file)
{
	if (getChar(it, input_file) == '*')
	{
		readings++; //indicates that it successfully read
		return true;
	}
	else
	{
		return false;
	}
}
