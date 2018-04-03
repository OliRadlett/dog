#include "Parser.h"

Parser::Parser()
{

}

std::vector<std::string>Parser::Parse(std::string fileString)
{
	std::vector < std::string> lines = Split(fileString, ";");
	return lines;
}

std::vector<std::string> Parser::Split(std::string _lines, const char* delimiter)
{
	// Split series of values by delimiter
	std::vector<std::string> lines;

	size_t pos = 0;
	std::string token;

	while ((pos = _lines.find(delimiter)) != std::string::npos)
	{
		token = _lines.substr(0, pos);
		lines.push_back(token);
		_lines.erase(0, pos + 1);
		
		while (_lines[0] == ' ')
		{
			_lines.erase(0, 1);
		}
	}

	return lines;
}

std::vector<int> Parser::parseInts(std::string ints)
{
	std::vector<std::string> intsStr = Split(ints, " ");
	std::vector<int> ints;
	for (std::string int_ : intsStr)
	{
		int number = int_;
	}
}

Parser::~Parser()
{
}