#pragma once

#ifndef INPUTPARSER_H
#define INPUTPARSER_H

#include <string>

#include "Enums.h"
#include "LoggerMultiton.h"
#include "SourceFile.h"

/*
* Parse a C# file into a SourceFile object
*/
class InputParser
{
public:
	InputParser(std::shared_ptr<ILogger> = LoggerMultiton::getLogger());
	~InputParser();

	SourceFile parse(const std::string& inputFilePath) const;

private:
	std::pair<Enums::categories, std::string> processLine(const std::string& line) const;
	std::shared_ptr<ILogger> m_logger;
};

#endif