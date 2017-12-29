#include "LogEntry.h"

#include <time.h>

#include "Utilities.h"

/*
* Constructor
* @param logLevel category for the message
* @param message message to log
*/
LogEntry::LogEntry(const std::string& logLevel, const std::string& message) : 
	m_timestamp(LogEntry::getTimestamp()), m_logLevel(logLevel), m_message(message)
{
}

/* Destructor */
LogEntry::~LogEntry() {}

/*
* Overload the stream operator to print the SourceFile as a C# test file
* with dependency injection done using NSubstitute
* @param os output stream to write to
* @param file LogFile to print
* @returns formatted output stream of the LogFile
*/
std::ostream& operator<<(std::ostream& os, const LogEntry& entry)
{
	// TODO Make the log level an enum or something more fixed
	os << entry.m_timestamp << ": "
		<< entry.m_logLevel << ": "
		<< entry.m_message << std::endl;
	return os;
}

/*
* Generate a timestamp based on the current time
* @return current time as a string
*/
std::string LogEntry::getTimestamp() const
{
	auto currentTime = time(NULL);
	return Utilities::trim(asctime(localtime(&currentTime)), "\n");
}