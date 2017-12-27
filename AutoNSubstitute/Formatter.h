#pragma once

#ifndef FORMATTER_H
#define FORMATTER_H

#include <string>

/*
* Format a file stored as a string
*/
class Formatter
{
public:
	Formatter();
	~Formatter();

	std::string format(const std::string& file) const;
};

#endif