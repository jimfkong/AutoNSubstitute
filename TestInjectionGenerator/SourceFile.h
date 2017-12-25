#pragma once

#ifndef SOURCEFILE_H
#define SOURCEFILE_H

#include <string>
#include <sstream>
#include <vector>

#include "Injection.h"

/* 
* C# file
*/
class SourceFile
{
public:
	SourceFile(std::string className, std::string nameSpace, 
		std::vector<Injection> injections);
	virtual ~SourceFile();

	friend std::ostream& operator<<(std::ostream& os, const SourceFile& file);

private:
	std::string m_class;
	std::string m_namespace;
	std::vector<Injection> m_injections;
};

#endif