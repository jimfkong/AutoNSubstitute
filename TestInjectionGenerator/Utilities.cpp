#include "Utilities.h"

#include <vector>
#include <fstream>
#include <sstream>
#include <string>

/* 
* Convert a string to a writeable c-string. 
* @param str string to conver
* @returns str as a writeable c-string
*/
char* Utilities::stringToCharStar(const std::string& str)
{
	std::vector<char> writeable(str.begin(), str.end());
	writeable.push_back('\0');

	return &writeable[0];
}

/*
* Read the file stored at the given path into a string
* @param path path to a file to be read
* @returns file stored as a string
*/
std::string Utilities::readFile(const std::string& path)
{
	std::string line;
	std::stringstream ss;

	auto ifs = openFile(path);

	if (ifs.is_open())
	{
		while (getline(ifs, line))
		{
			ss << line;
		}

		ss << std::endl;
	}

	return ss.str();
}

/*
* Read a file and return the file as a vector of lines
* @param path path to the file to be read
* @returns vector of each line in the file stored as strings
*/
std::vector<std::string> Utilities::readLineByLine(const std::string& path)
{
	std::string line;
	std::vector<std::string> output;

	auto ifs = openFile(path);

	if (ifs.is_open())
	{
		while (getline(ifs, line))
		{
			output.push_back(line);
		}
	}

	return output;
}

/* 
* Check if a string starts with a given sub-string
* @param str string to check the start of
* @param substr string to find
* @returns true if str starts with substr, otherwise false
*/
bool Utilities::stringStartsWith(const std::string& str, const std::string& substr)
{
	auto len_substr = substr.length();
	if (strncmp(substr.c_str(), str.c_str(), len_substr) == 0)
	{
		return true;
	}

	return false;
}

/*
* Trim leading and trailing characters from a string
* @param str string to trim
* @param whitespace defaults to ' '. Char to trim from given string
* @returns input string with leading and trailing characters removed
*/
std::string Utilities::trim(const std::string& str,
	const std::string& whitespace)
{
	const auto strBegin = str.find_first_not_of(whitespace);
	if (strBegin == std::string::npos)
		return ""; // no content

	const auto strEnd = str.find_last_not_of(whitespace);
	const auto strRange = strEnd - strBegin + 1;

	return str.substr(strBegin, strRange);
}

/* 
* Opens a given file
* @param path path to the file to open
* @returns file at given path as an ifstream
*/
std::ifstream Utilities::openFile(const std::string& path)
{
	std::ifstream ifs;

	try 
	{
		ifs.open(path);
	}
	catch (std::ifstream::failure failure)
	{
		throw failure;
	}

	return ifs;
}