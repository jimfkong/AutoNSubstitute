#include "SourceFile.h"

/* 
* Constructor 
* @param className name of the C# class
* @param nameSpace namespace the C# class belongs to
* @param injections vector of dependency injections used by the C# class
*/
SourceFile::SourceFile(
	std::string className, 
	std::string nameSpace, 
	std::vector<Injection> injections) : 
	m_class(className), m_namespace(nameSpace), m_injections(injections)
{}

/* Destructor */
SourceFile:: ~SourceFile() {}

/*
* Overload the stream operator to print the SourceFile as a C# test file
* with dependency injection done using NSubstitute
* @param os output stream to write to
* @param file SourceFile to print
* @returns output stream of the SourceFile instance as a C# test file
*/
std::ostream& operator<<(std::ostream& os, const SourceFile& file)
{
	// TODO Make some of these more generic
	// TODO Import namespaces for injections
	// TODO Error checking
	os << "using NSubstitute;" << std::endl;
	os << "using " << file.m_namespace << std::endl << std::endl;
	os << "public namespace UnitTests." << file.m_namespace << std::endl;
	os << "{" << std::endl;
	os << "[TestFixture]" << std::endl;
	os << "public class " << file.m_class << "Tests" << std::endl;
	os << "{" << std::endl;
	
	for (auto it = file.m_injections.begin(); it != file.m_injections.end(); ++it)
	{
		os << "private " << it->getInterfaceName() << " " 
			<< it->generateClassName() << ";" << std::endl;
	}

	os << std::endl;
	os << "[SetUp]" << std::endl;
	os << "public void Setup()" << std::endl;
	os << "{" << std::endl;

	for (auto it = file.m_injections.begin(); it != file.m_injections.end(); ++it)
	{
		os << it->generateClassName() << " = Substitute.For<" 
			<< it->getInterfaceName() << ">();" << std::endl;
	}

	os << "}" << std::endl << "}" << std::endl << "}" << std::endl;

	return os;
}
