#pragma once

#ifndef LOGGERMULTITON_H
#define LOGGERMULTITON_H

#include <unordered_map>
#include <memory>
#include <string>

#include "ILogger.h"

/*
* Multiton of ILoggers.
* Manages all ILogger instances by a given key. If no logger with the requested
* key exists, a new logger is created. Otherwise, it returns the existing logger.
*/
class LoggerMultiton
{
public:
	// TODO Dump logs to file
	static std::shared_ptr<ILogger> getLogger(std::string key = "default");

private:
	typedef std::unordered_map<std::string, std::shared_ptr<ILogger>> LoggerMap;

	LoggerMultiton();
	~LoggerMultiton();
	static LoggerMap initMap();

	static LoggerMap m_loggers;
};

#endif