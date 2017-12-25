#pragma once

#ifndef ILOGGER_H
#define ILOGGER_H

#include <string>

/*
* Logger interface
*/
class ILogger
{
public:
	virtual void log(const std::string& logLevel, const std::string& message) = 0;
};

#endif
