#include "InputParser.h"
#include "Formatter.h"

#include <iostream>

int main()
{
	// TODO Pass input file and output file via args
	// TODO Make own shared namespace for all these files
	InputParser inputParser;
	Formatter formatter;

	const auto sourceFile = inputParser.parse("TestClass.cs");
	std::ostringstream oss;
	oss << sourceFile;
	std::cout << formatter.format(oss.str()) << std::endl;
}