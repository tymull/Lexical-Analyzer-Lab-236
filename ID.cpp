#include "ID.h"


ID::ID()
{
}


ID::~ID()
{
}

int ID::getReadings()
{
	return readings;
}

bool ID::stillID(int it, const vector <char>& input_file)
{
	if (isalnum(getChar(it, input_file)))
	{
		readings++;
		it++;
		return stillID(it, input_file);
	}
	//HAVE TO FIX THIS '\xff' is eof right click and make text file
	else if (isblank(getChar(it, input_file)) || getChar(it, input_file) == '\n' || getChar(it, input_file) == '\xff')
	{
		return true; //will only accept if the next character is blank or EOF or new line.
	}
	else
	{
		return false;
	}
}

bool ID::read(int it, const vector <char>& input_file)
{
	if (isalpha(getChar(it, input_file))) //checks to see if first character is a letter
	{
		readings++; //indicates that it successfully read
		it++;
		return stillID(it, input_file);
	}
	else
	{
		return false;
	}
}
