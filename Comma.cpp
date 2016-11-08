#include "Comma.h"

Comma::Comma()
{
}


Comma::~Comma()
{
}

int Comma::getReadings()
{
	return readings;
}

/*
bool Comma::getChar()
{
	
}
*/

bool Comma::read(int it, const vector <char>& input_file)
{
	if (getChar(it, input_file) == ',') //checks to see if current iteration is a ','
	{
		readings++; //indicates that it successfully read
		return true;
	}
	else
	{
		return false;
	}
}

Token Comma::tokenize(int it, const vector <char>& input_file)
{
	string name = "COMMA";
	string content(input_file[it], input_file[it + readings]);
	int line = 1;
	Token token(name, content, line);
	return token;
}
