#pragma once

#include <string>
#include <vector>

class vars
{
public:
	vars();
	~vars();
	static void InitString(std::string name, std::string value);
	static void InitDouble (std::string name, double value);
	static void InitBoolean(std::string name, bool value);
};