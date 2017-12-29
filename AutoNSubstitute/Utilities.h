#pragma once

#ifndef UTILITIES_H
#define UTILITIES_H

#include <memory>
#include <sstream>
#include <string>
#include <unordered_map>
#include <vector>

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

	/*
	* Print a container to string.
	* Assumes the contents of the container overrides the stream operator.
	* @param container container to print
	* @param printNewLines If true, prints a new line between each container element
	* @returns container contents as a string
	*/
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

	/*
	* Returns true if the given key is found in the map. 
	* @param in map to search
	* @param key key to find
	* @returns true if key is in map, false otherwise
	*/
	template<typename T, typename T2>
	static bool keyInMap(const std::unordered_map<T, T2>& in, const T& key)
	{
		// TODO Make this support std::Map as well
		return (in.find(key) != in.end());
	}

private:
	static std::ifstream openFile(const std::string& path);
};

#endif