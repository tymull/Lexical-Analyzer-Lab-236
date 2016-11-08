#include "QMark.h"


QMark::QMark()
{
}


QMark::~QMark()
{
}

int QMark::getReadings()
{
	return readings;
}

bool QMark::read(int it, const vector <char>& input_file)
{
	if (getChar(it, input_file) == '?')
	{
		readings++; //indicates that it successfully read
		return true;
	}
	else
	{
		return false;
	}
}
