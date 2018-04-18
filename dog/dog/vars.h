#pragma once

#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

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
	static bool findStr(std::string name);
	static bool findNum(std::string name);
	static bool findBoo(std::string name);
	static std::string getString(std::string name);
	static double getNumber(std::string name);
	static bool getBoolean(std::string name);
	static void remove(std::vector<std::string> vector, std::string value);
	static void remove(std::vector<double> &vector, double value);
	static void remove(std::vector<bool> &vector, bool value);
};