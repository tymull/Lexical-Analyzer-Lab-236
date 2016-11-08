#include "Schemes.h"


Schemes::Schemes()
{
}


Schemes::~Schemes()
{
}

int Schemes::getReadings()
{
	return readings;
}

bool Schemes::s(int it, const vector <char>& input_file)
{
	if (getChar(it, input_file) == 's')
	{
		readings++;
		return true;
	}
	else
	{
		return false;
	}
}

bool Schemes::e2(int it, const vector <char>& input_file)
{
	if (getChar(it, input_file) == 'e')
	{
		readings++;
		return s(it, input_file);
	}
	else
	{
		return false;
	}
}

bool Schemes::m(int it, const vector <char>& input_file)
{
	if (getChar(it, input_file) == 'm')
	{
		readings++;
		it++;
		return e2(it, input_file);
	}
	else
	{
		return false;
	}
}

bool Schemes::e1(int it, const vector <char>& input_file)
{
	if (getChar(it, input_file) == 'e')
	{
		readings++;
		it++;
		return m(it, input_file);
	}
	else
	{
		return false;
	}
}

bool Schemes::h(int it, const vector <char>& input_file)
{
	if (getChar(it, input_file) == 'h')
	{
		readings++;
		it++;
		return e1(it, input_file);
	}
	else
	{
		return false;
	}
}

bool Schemes::c(int it, const vector <char>& input_file)
{
	if (getChar(it, input_file) == 'c')
	{
		readings++;
		it++;
		return h(it, input_file);
	}
	else
	{
		return false;
	}
}

bool Schemes::read(int it, const vector <char>& input_file)
{
	if (getChar(it, input_file) == 'S')
	{
		readings++; //indicates that it successfully read
		it++; //to go to next point in vector in recursion. IF SEGFAULTS CHECK HERE--may be iterating to impossible amount
		return c(it, input_file);
	}
	else
	{
		return false;
	}
}