#include "Formatter.h"

#include <sstream>

#include "Utilities.h"

/* Constructor */
Formatter::Formatter() {}

/* Destructor */
Formatter::~Formatter() {}

/*
* Format an unformatted file stored as a string
* Adds indenting to a file where lines are terminated by '/n'
* @param file file to be parsed stored as a string
* @return formatted version of the input file
*/
std::string Formatter::format(const std::string& file) const
{
	// TODO Support tabs and spaces
	// TODO Support braces on same line
	// TODO Support for lines terminated by ';' - i.e. completely unformatted
	const auto indentSize = 4;
	auto nIndents = 0;

	std::istringstream iss(file);
	std::ostringstream oss;
	std::string line;

	while (getline(iss, line)) {
		if (Utilities::trim(line).compare("}") == 0)
		{
			nIndents -= 1;
		}

		line.insert(0, (indentSize * nIndents), ' ');

		oss << line << std::endl;

		if (Utilities::trim(line).compare("{") == 0)
		{
			nIndents += 1;
		}
	}

	return oss.str();
}