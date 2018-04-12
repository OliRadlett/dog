#include "vars.h"

std::vector<std::string> stringNames;
std::vector<std::string> stringValues;
std::vector<std::string> doubleNames;
std::vector<double> doubleValues;
std::vector<std::string> booleanNames;
std::vector<bool> booleanValues;

vars::vars()
{
}


vars::~vars()
{
}

void vars::InitString(std::string name, std::string value)
{
	if (exists(name))
	{
		stringNames.push_back(name);
		stringValues.push_back(value);
	}
}

void vars::InitDouble(std::string name, double value)
{
	doubleNames.push_back(name);
	doubleValues.push_back(value);
}

void vars::InitBoolean(std::string name, bool value)
{
	booleanNames.push_back(name);
	booleanValues.push_back(value);
}

bool vars::exists(std::string name)
{
	if (std::find(stringNames.begin(), stringNames.end(), name) != stringNames.end())
	{
		return true;
	}
	if (std::find(doubleNames.begin(), doubleNames.end(), name) != doubleNames.end())
	{
		return true;
	}
	if (std::find(booleanNames.begin(), booleanNames.end(), name) != booleanNames.end())
	{
		return true;
	}
	return false;
}