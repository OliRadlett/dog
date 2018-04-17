#pragma once
#include <vector>
#include <iostream>
#include <string>
#include <sstream>
#include <iterator>
#include "DebugFunctions.h"

class Parser
{
public:
	Parser();
	~Parser();
	std::vector<std::string>Parse(std::string fileString);
	std::vector<int>parseInts(std::string ints);
	std::vector<double>parseDoubles(std::string doubles);
	std::vector<float>parseFloats(std::string floats);
	std::vector<std::string> Split(std::string _lines, const char* delimiter, bool includeLast);
	std::vector<std::string> ParseInitString(std::string line);
	std::vector<std::string> ParseInitDouble(std::string line);
	std::vector<std::string> ParseInitBoolean(std::string line);
};
