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

std::vector<float> Parser::parseFloats(std::string floats)
{
	// Var names in this method make no sense.
	std::vector<std::string> floatsStr = Split(floats, " ", true);
	DebugFunctions dbf;
	//dbf.OutputVector(intsStr);
	std::vector<float> numbers;
	for (std::string float_ : floatsStr)
	{
		float number = std::stod(float_);
		numbers.push_back(number);
	}
	return numbers;
}

std::vector<std::string> Parser::ParseInitString(std::string line)
{
	std::vector<std::string> SplitLine = Split(line, " ", true);
	std::string name = SplitLine[1];
	std::string value;
	for (int i = 2; i < SplitLine.size(); i++)
	{
		value.append(SplitLine[i]);
		if (i != SplitLine.size() - 1)
		{
			value.append(" ");
		}
	}
	std::vector < std::string> parsedStr = { name, value };
	return parsedStr;
}

std::vector<std::string> Parser::ParseInitDouble(std::string line)
{
	std::vector<std::string> SplitLine = Split(line, " ", true);
	std::string name = SplitLine[1];
	std::string value = SplitLine[2];
	std::vector < std::string> parsedStr = { name, value };
	return parsedStr;
}

// Too tired to work if if these are two seperate functions doing similar things, or identical functions doing identical things

std::vector<std::string> Parser::ParseInitBoolean(std::string line)
{
	std::vector<std::string> SplitLine = Split(line, " ", true);
	std::string name = SplitLine[1];
	std::string value = SplitLine[2];
	std::vector < std::string> parsedStr = { name, value };
	return parsedStr;
}

std::vector<std::string> Parser::parseConditional(std::string line)
{
	size_t start = line.find_first_of("(") + 1;
	size_t end = line.find_last_of(")");
	int length = end - start;
	std::string conditional = line.substr(start, length);
	std::vector<std::string> parsedConditional = Parser::Split(conditional, " ", true);
	return parsedConditional;

}

Parser::~Parser()
{
}