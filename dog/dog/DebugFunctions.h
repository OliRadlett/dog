#pragma once
#include <vector>
#include <iostream>
#include <string>

class DebugFunctions
{
public:
	DebugFunctions();
	~DebugFunctions();
	void OutputVector(std::vector<std::string> vector);
	void OutputVector(std::vector<int> vector);
	void OutputVector(std::vector<char> vector);
	void OutputVector(std::vector<const char> vector);
};