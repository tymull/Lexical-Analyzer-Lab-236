#pragma once
#include "Automaton.h"
//class LexicalAnalyzer;
class Comma : 
	public Automaton
{
private:
	int readings = 0; //number of characters read by this machine
	//LexicalAnalyzer* lex(char* input);
public:
	Comma();
	~Comma();
	int getReadings();
	//bool getChar(); //Will see if current character is a ','
	bool read(int it, const vector <char>& input_file);
	void resetReadings();
	Token tokenize(unsigned int& current_line, int it, const vector <char>& input_file);
};

