#include "LexicalAnalyzer.h"


LexicalAnalyzer::LexicalAnalyzer(char* input_file)
{
	char character;
	ifstream file_to_read(input_file);
	if (file_to_read.is_open())
	{
		while (!file_to_read.eof())
		{
			file_to_read >> character;
			this->input_file.push_back(character); //reads the file into the data member
		}
		file_to_read.close();
	}
	else
	{
		cout << "unable to read file";
	}
}


LexicalAnalyzer::~LexicalAnalyzer()
{
}

vector <char> LexicalAnalyzer::getInputFile()
{
	return input_file;
}

void LexicalAnalyzer::analyze(char* input_file)
{
	char character;
	ifstream file_to_read(input_file);
	if (file_to_read.is_open())
	{
		while (!file_to_read.eof())
		{
			file_to_read >> character;
			this->input_file.push_back(character); //reads the file into the data member
		}
		file_to_read.close();
	}
	else
	{
		cout << "unable to read file";
	}
}

char LexicalAnalyzer::getChar(int it)
{
	return input_file[it]; //returns character at given iteration.
}

/*
void LexicalAnalyzer::reset()
{

}
*/

string LexicalAnalyzer::scan()
{
	

	//the following vectors order automata by precidence
	vector <Automaton*> automata;
	vector <int> automata_readings;
	vector <Token> tokens;
	int max_readings = 0;
	int new_max_readings = 0;
	int it_of_max_readings = -1; //current iteration of max readings. initialized to -1 in case none read.
	unsigned int current_iteration = 0; //this is first iteration for iterating through file. Can increment after tokens made
	unsigned int current_line = 1; //current line in file starts at 1

	automata.push_back(new Comma());
	automata.push_back(new Period());
	automata.push_back(new QMark());
	automata.push_back(new LeftParen());
	automata.push_back(new RightParen());
	automata.push_back(new Colon());
	automata.push_back(new ColonDash());
	automata.push_back(new Multiply());
	automata.push_back(new Add());
	automata.push_back(new Schemes());
	automata.push_back(new Facts());
	automata.push_back(new Rules());
	automata.push_back(new Queries());
	automata.push_back(new ID());
	automata.push_back(new MyString());
	automata.push_back(new Comment());
	automata.push_back(new WhiteSpace());

	while (current_iteration <= input_file.size())
	{
		for (unsigned int i = current_iteration; i < input_file.size(); i++) //this loop iterates through file
		{
			for (unsigned int j = 0; j < automata.size(); j++)//this loop lets each automata read current iteration
			{
				automata[j]->read(i, input_file); //MAY HAVE to increment i extra based on amount read
				//finds which automata has most readings and highest precidence.
				new_max_readings = max(max_readings, automata[j]->getReadings());
				/*this will change it_of_max_readings to match the automata with max readings while keeping
				precidence by only changing if it exceeds the previous max.*/
				if (new_max_readings > max_readings)
				{
					it_of_max_readings = j;
					max_readings = new_max_readings;
				}
			}
		}
		tokens.push_back(automata[it_of_max_readings]->tokenize(current_iteration, input_file));
		current_iteration += max_readings; //move iteration to point beyond end of last token made
	} 
	string name_EOF = "EOF";
	string content_EOF = "";
	Token token_EOF(name_EOF, content_EOF, current_line);
	tokens.push_back(token_EOF);
	stringstream token_list;
	for (unsigned int i = 0; i < tokens.size(); i++)
	{
		token_list << tokens[i].getToken();
		if (i < tokens.size() -1)//if i is not on the last token (EOF)
		{
			token_list << endl;
		}
	}
	return token_list.str();
}
