#include "Logger.h"

#include <iostream>

// TODO Do we want to import utilities? Introduces tighter coupling
#include "Utilities.h"

/* Constructor */
Logger::Logger() {}

/* Destructor */
Logger::~Logger() {}

/*
* Log a new message
* @param logLevel category of the message
* @param message message to log
*/
void Logger::log(const std::string& logLevel, const std::string& message) 
{
	// TODO Add the option to supress specific log levels - maybe add a loggerConfig object?
	m_messages.push_back(LogEntry(logLevel, message));
}

/*
* Write the messages to output
* @param os output stream to write to
* @returns given output stream with logger messages added
*/
std::ostream& Logger::write(std::ostream& os) const
{
	os << Utilities::printContainer(m_messages, false);

	return os;
}