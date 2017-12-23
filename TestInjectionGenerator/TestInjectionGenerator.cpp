#include "InputParser.h"
#include "Formatter.h"

#include <iostream>

int main()
{
	InputParser inputParser;
	Formatter formatter;

	const auto sourceFile = inputParser.parse("TestClass.cs");
	std::ostringstream oss;
	oss << sourceFile;
	std::cout << formatter.format(oss.str()) << std::endl;
}