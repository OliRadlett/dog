#include "Parser.h"

Parser::Parser()
{

}

std::vector<std::string>Parser::Parse(std::string fileString)
{
	std::vector < std::string> lines = Split(fileString, ";", false);
	return lines;
}

std::vector<std::string> Parser::Split(std::string _lines, const char* delimiter, bool includeLast)
{
	// Add a boolean parameter for getting the last part of line if there is no delimiter i.e. the last number in the add command that isn't followed by a space
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
		while (_lines[0] == '\n')
		{
			_lines.erase(0, 1);
		}
	}

	if (includeLast)
	{
		lines.push_back(_lines);
	}

	return lines;
}

std::vector<int> Parser::parseInts(std::string ints)
{
	// Var names in this method make no sense.
	std::vector<std::string> intsStr = Split(ints, " ", true);
	DebugFunctions dbf;
	//dbf.OutputVector(intsStr);
	std::vector<int> numbers;
	for (std::string int_ : intsStr)
	{
		int number = std::stoi(int_);
		numbers.push_back(number);
	}
	return numbers;
}

std::vector<double> Parser::parseDoubles(std::string doubles)
{
	// Var names in this method make no sense.
	std::vector<std::string> doublesStr = Split(doubles, " ", true);
	DebugFunctions dbf;
	//dbf.OutputVector(intsStr);
	std::vector<double> numbers;
	for (std::string double_ : doublesStr)
	{
		double number = std::stod(double_);
		numbers.push_back(number);
	}
	return numbers;
}

Parser::~Parser()
{
}