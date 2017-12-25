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
	m_messages.push_back(LogEntry(logLevel, message));
}

std::ostream& operator<<(std::ostream& os, const Logger& logger)
{
	os << Utilities::printContainer(logger.m_messages, false);

	return os;
}