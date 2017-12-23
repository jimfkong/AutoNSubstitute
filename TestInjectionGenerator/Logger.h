#pragma once

#ifndef LOGGER_H
#define LOGGER_H

#include "ILogger.h"
#include "LoggerMultiton.h"

#include <memory>
#include <string>

/*
* Log messages generated by the code
*/
class Logger : public ILogger
{
public:
	// TODO Destructor is public because of shared pointer. Investigate make_shared?
	~Logger();

	void log();

private:
	Logger(const std::string& name);
	friend std::shared_ptr<ILogger> LoggerMultiton::getLogger(std::string key);

	std::string m_name;
};

#endif