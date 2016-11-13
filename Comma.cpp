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
		cout << "Comma readings=" << readings;
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
	string content(input_file.begin() + it, input_file.begin() + it + readings); // for some crazy reason, can't put input_file[it]
	int line = 1;
	Token token(name, content, line);
	return token;
}
