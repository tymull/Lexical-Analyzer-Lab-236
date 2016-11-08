#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <algorithm>

#include "Token.h"
#include "Automaton.h"
#include "Comma.h"
#include "Period.h"
#include "QMark.h"
#include "LeftParen.h"
#include "RightParen.h"
#include "Colon.h"
#include "ColonDash.h"
#include "Multiply.h"
#include "Add.h"
#include "Schemes.h"
#include "Facts.h"
#include "Rules.h"
#include "Queries.h"
#include "ID.h"
#include "MyString.h"
#include "Comment.h"
#include "WhiteSpace.h"

using namespace std;

class LexicalAnalyzer
{
	friend class Comma;
protected:
	vector <char> input_file;
	vector <char> temp_file;
	int current_iteration = 0; //this marks where in input_file we begin reading
public:
	LexicalAnalyzer(char* input_file);
	~LexicalAnalyzer(); //&input file as a paramater
	vector <char> getInputFile();
	void analyze(char* input_file); //can change value of input_file
	char getChar(int it);
	//void reset(); //replaces the input_file with the new temp_file to restore the original.
	string scan(); //will scan file using all automata subclasses and output tokens

};

