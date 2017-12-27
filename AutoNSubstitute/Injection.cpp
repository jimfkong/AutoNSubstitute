#include "Injection.h"

#include <cctype>

/*
* Constructor
* @param interfaceName name of the abstract class that is being injected
*/
Injection::Injection(std::string interfaceName) : 
	m_interfaceName(interfaceName) 
{}

/* Destructor */
Injection::~Injection() {}

/*
* Getter for the interface/class name
* @return the name of the abstract class
*/
const std::string Injection::getInterfaceName() const
{
	return m_interfaceName;
}

/* 
* Generate a variable name based on the interface name
* @return variable name based on the interface name
*/
std::string Injection::generateClassName() const
{
	std::string className = m_interfaceName;
	if (className[0] == 'I') 
	{
		className[0] = '_';
	}
	else
	{
		className = '_' + className;
	}

	className[1] = std::tolower(className[1]);

	return className;
}
