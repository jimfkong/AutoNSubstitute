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
	virtual std::ostream& write(std::ostream& os) const = 0;
};

/*
* Overload the stream operator to print the logger.
* @param os output stream to print to
* @param logger logger to print
* @returns passed output stream with logger written to it
*/
inline std::ostream& operator<<(std::ostream& os, const ILogger& logger)
{
	return logger.write(os);
}

#endif
