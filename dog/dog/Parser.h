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
	std::vector<std::string> Split(std::string _lines, const char* delimiter, bool includeLast);
};
