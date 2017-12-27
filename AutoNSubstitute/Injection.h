#pragma once

#ifndef INJECTION_H
#define INJECTION_H

#include <string>

/*
* C# dependency injection
*/
class Injection
{
public:
	Injection(std::string interfaceName);
	virtual ~Injection();

	const std::string getInterfaceName() const;
	std::string generateClassName() const;

private:
	std::string m_interfaceName;
};

#endif