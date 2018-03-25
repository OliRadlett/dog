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

private:
	std::vector<std::string> SplitFile(std::string fileString);
};
