#include "LeftParen.h"


LeftParen::LeftParen()
{
}


LeftParen::~LeftParen()
{
}

int LeftParen::getReadings()
{
	return readings;
}

bool LeftParen::read(int it, const vector <char>& input_file)
{
	if (getChar(it, input_file) == '(')
	{
		readings++; //indicates that it successfully read
		return true;
	}
	else
	{
		return false;
	}
}
