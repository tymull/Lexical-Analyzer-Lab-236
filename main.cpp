
#include <iostream>
#include "LexicalAnalyzer.h"
using namespace std;

int main(int argc, char* argv[])
{
	LexicalAnalyzer lexi(argv[1]);
	cout << lexi.scan();

	return 0;
}
