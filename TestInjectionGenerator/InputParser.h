#pragma once

#ifndef INPUTPARSER_H
#define INPUTPARSER_H

#include <string>

#include "SourceFile.h"
#include "Enums.h"

/*
* Parse a C# file into a SourceFile object
*/
class InputParser
{
public:
	InputParser();
	~InputParser();

	SourceFile parse(const std::string& inputFilePath) const;

private:
	std::pair<Enums::categories, std::string> processLine(const std::string& line) const;
};

#endif