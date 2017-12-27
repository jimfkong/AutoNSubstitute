#pragma once

#ifndef LOGENTRY_H
#define LOGENTRY_H

#include <string>

/* 
* Entry in the logger
*/
class LogEntry
{
public:
	LogEntry(const std::string& logLevel, const std::string& message);
	~LogEntry();

	friend std::ostream& operator<<(std::ostream& os, const LogEntry& entry);

private:
	std::string getTimestamp() const;

	std::string m_timestamp;
	std::string m_logLevel;
	std::string m_message;
};

#endif