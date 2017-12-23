#pragma once

#ifndef OUTPUTPARSER_H
#define OUTPUTPARSER_H

#include <string>

#include "SourceFile.h"

/*
* Parse a SourceFile object into a C# file
*/
class OutputParser
{
public:
	OutputParser();
	~OutputParser();

	void parse(SourceFile source, std::string outputLocation) const;
};

#endif