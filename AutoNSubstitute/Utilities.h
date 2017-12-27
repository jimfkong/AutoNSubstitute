#pragma once

#ifndef UTILITIES_H
#define UTILITIES_H

#include <string>
#include <vector>
#include <sstream>

/*
* Collection of basic utility functions
*/
class Utilities
{
public:
	static char* stringToCharStar(const std::string& str);
	static std::string readFile(const std::string& path);
	static std::vector<std::string> readLineByLine(const std::string& path);
	static bool stringStartsWith(const std::string& str, const std::string& substr);
	static std::string trim(const std::string& str, const std::string& whitespace = " ");

	/*
	* Check if a given value is present within the given container.
	* @param container container to search
	* @param value value to find
	*/
	template<typename T, typename Container>
	static bool isInContainer(const Container& container, const T value)
	{
		return container.find(value) != container.end();
	}

	template<typename Container>
	static std::string printContainer(const Container& container, bool printNewLines)
	{
		std::ostringstream containerString;

		for (auto it = container.begin(); it != container.end(); ++it)
		{
			containerString << *it;
			if (printNewLines)
			{
				containerString << std::endl;
			}
		}

		return containerString.str();
	}

private:
	static std::ifstream openFile(const std::string& path);
};

#endif