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
	stringNames.push_back(name);
	stringValues.push_back(value);
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