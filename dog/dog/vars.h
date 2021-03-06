#pragma once

#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include "DebugFunctions.h"

class vars
{
public:
	vars();
	~vars();
	static void InitString(std::string name, std::string value);
	static void InitDouble (std::string name, double value);
	static void InitBoolean(std::string name, bool value);
	static bool exists(std::string name);
	static void deleteVar(std::string name);
	static bool findString(std::string name);
	static bool findNumber(std::string name);
	static bool findBoolean(std::string name);
	static std::string getString(std::string name);
	static double getNumber(std::string name);
	static bool getBoolean(std::string name);
	static std::vector<std::string> remove(std::vector<std::string> vector, std::string value);
	static std::vector<double> remove(std::vector<double> vector, double value);
	static std::vector<bool> remove(std::vector<bool> vector, bool value);
	static std::string getType(std::string varName);
};