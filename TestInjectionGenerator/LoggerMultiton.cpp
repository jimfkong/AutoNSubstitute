#include "LoggerMultiton.h"

#include "Logger.h"
#include "Utilities.h"

LoggerMultiton::LoggerMap LoggerMultiton::m_loggers = LoggerMultiton::initMap();

/* Constructor */
LoggerMultiton::LoggerMultiton() {}

/* Destructor */
LoggerMultiton::~LoggerMultiton() 
{
	// TODO Double check that we don't need to delete the map - should be auto cleaned
	// m_loggers.erase(m_loggers.begin(), m_loggers.end());
}

/* 
* Create a new LoggerMap instance
* @return new LoggerMap
*/
LoggerMultiton::LoggerMap LoggerMultiton::initMap()
{
	return LoggerMultiton::LoggerMap();
}

/*
* Retrieve a pointer to a logger instance based on the passed key. 
* If no logger exists for the given key, a new logger will be created.
* Otherwise, the existing logger is returned.
* @param key key to the logger to retrieve
* @return shared pointer to a logger instance
*/
std::shared_ptr<ILogger> LoggerMultiton::getLogger(std::string key)
{
	if (Utilities::isInContainer(m_loggers, key))
	{
		return m_loggers[key];
	}
	else
	{
		std::shared_ptr<ILogger> logger(new Logger(key));
		m_loggers[key] = logger;
		return logger;
	}
}