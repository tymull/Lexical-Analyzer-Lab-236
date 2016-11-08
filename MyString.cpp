#include "MyString.h"


MyString::MyString()
{
}


MyString::~MyString()
{
}

int MyString::getReadings()
{
	return readings;
}

bool MyString::endString(int it, const vector <char>& input_file)
{
	if (getChar(it, input_file) == '\'')
	{
		readings++; //indicates that it successfully read
		it++;
		return isStuff(it, input_file); //if it has another ', will continue reading
	}
	else
	{
		return true;
	}
}

bool MyString::isStuff(int it, const vector <char>& input_file)
{
	if (getChar(it, input_file) == '\'')
	{
		readings++;
		it++;
		return endString(it, input_file);
	}
	else if (getChar(it, input_file) == '\xff')
	{
		return false; //this makes it undefined
	}
	else
	{
		readings++;
		it++;
		return isStuff(it, input_file);
	}
}

bool MyString::read(int it, const vector <char>& input_file)
{
	if (getChar(it, input_file) == '\'')
	{
		readings++; //indicates that it successfully read
		it++;
		return isStuff(it, input_file);
	}
	else
	{
		return false;
	}
}
