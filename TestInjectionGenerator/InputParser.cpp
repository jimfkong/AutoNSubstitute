#include "InputParser.h"

#include "Utilities.h"

#include <iostream>
#include <regex>
#include <string>

/* Constructor */
InputParser::InputParser() {}

/* Destructor */
InputParser::~InputParser() {}

/*
* Convert a C# file into a SourceFile object
* @param inputFilePath path to the C# file to parse
* @return parsed C# file stored as a SourceFile object
*/
SourceFile InputParser::parse(const std::string& inputFilePath) const
{
	const auto file = Utilities::readLineByLine(inputFilePath);
	std::string nameSpace;
	std::string className;
	std::vector<Injection> injections;

	// TODO Implement logger for warnings if namespace or class are assigned more than once
	for (auto it = file.begin(); it != file.end(); it++)
	{
		const auto line = Utilities::trim(*it);
		const auto result = processLine(line);

		switch (result.first)
		{
			case Enums::categories::nameSpace:
			{
				nameSpace = result.second;

				break;
			}
			case Enums::categories::injection:
			{
				const Injection injection(result.second);
				injections.push_back(injection);

				break;
			}
			case Enums::categories::className:
			{
				className = result.second;

				break;
			}
			case Enums::categories::invalid:
			default:
			{
				continue;
			}
		}
	}

	SourceFile sourceFile(className, nameSpace, injections);
	return sourceFile;
}

/*
* Process a line in the C# source file
* Categorise the given line and convert the line into the format
* that category requires.
* @param line line from C# file to be parsed
* @return pair containing the category and parsed input line, in that order
*/
std::pair<Enums::categories, std::string> InputParser::processLine(
	const std::string& line) const
{
	// TODO Place those values in a config manager
	// TODO Support differing case
	const std::regex NAMESPACE_PATTERN("^(public namespace )(.+)$");
	const auto NAMESPACE_REPLACER = "$2";
	const std::regex INJECTION_PATTERN("^(private )(I.+)( .+)$");
	const auto INJECTION_REPLACER = "$2";
	const std::regex CLASS_PATTERN("(public class )(.+)(\\(.*\\))");
	const auto CLASS_REPLACER = "$2";

	if (Utilities::stringStartsWith(line, "public namespace"))
	{
		return std::make_pair(Enums::categories::nameSpace, std::regex_replace(line,
			NAMESPACE_PATTERN, NAMESPACE_REPLACER));
	}
	else if (Utilities::stringStartsWith(line, "private I"))
	{
		return std::make_pair(Enums::categories::injection, std::regex_replace(line,
			INJECTION_PATTERN, INJECTION_REPLACER));
	}
	else if (Utilities::stringStartsWith(line, "public class"))
	{
		return std::make_pair(Enums::categories::className, std::regex_replace(line, 
			CLASS_PATTERN, CLASS_REPLACER));
	}

	return std::make_pair(Enums::categories::invalid, "");
}