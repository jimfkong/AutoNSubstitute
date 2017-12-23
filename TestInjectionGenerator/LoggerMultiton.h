#pragma once

#ifndef LOGGERMULTITON_H
#define LOGGERMULTITON_H

#include <map>
#include <memory>
#include <string>

#include "ILogger.h"

// TODO Should this be static?
class LoggerMultiton
{
public:
	LoggerMultiton();
	~LoggerMultiton();

	std::shared_ptr<ILogger> getLogger(std::string key = "default");

private:
	std::map<std::string, std::shared_ptr<ILogger>> m_loggers;
};

#endif