#include "LoggerMultiton.h"

#include "Logger.h"
#include "Utilities.h"

LoggerMultiton::LoggerMultiton() 
{
	m_loggers = std::map<std::string, std::shared_ptr<ILogger>>();
}

LoggerMultiton::~LoggerMultiton() 
{
	m_loggers.erase(m_loggers.begin(), m_loggers.end());
}

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