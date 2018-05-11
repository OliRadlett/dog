#include "vars.h"
#include "stdafx.h"

std::vector<std::string> stringNames;
std::vector<std::string> stringValues;
std::vector<std::string> doubleNames;
std::vector<double> doubleValues;
std::vector<std::string> booleanNames;
std::vector<bool> booleanValues;
//DebugFunctions dbf;

vars::vars()
{
}


vars::~vars()
{
}

void vars::InitString(std::string name, std::string value)
{
	if (!exists(name))
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

bool vars::findStr(std::string name)
{
	if (std::find(stringNames.begin(), stringNames.end(), name) != stringNames.end())
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool vars::findNum(std::string name)
{
	if (std::find(doubleNames.begin(), doubleNames.end(), name) != doubleNames.end())
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool vars::findBoo(std::string name)
{
	if (std::find(booleanNames.begin(), booleanNames.end(), name) != booleanNames.end())
	{
		return true;
	}
	else
	{
		return false;
	}
}

std::vector<std::string> vars::remove(std::vector<std::string> vector, std::string value)
{
	vector.erase(std::remove(vector.begin(), vector.end(), value), vector.end());
	return vector;
}

std::vector<double> vars::remove(std::vector<double> vector, double value)
{
	vector.erase(std::remove(vector.begin(), vector.end(), value), vector.end());
	return vector;
}

std::vector<bool> vars::remove(std::vector<bool> vector, bool value)
{
	vector.erase(std::remove(vector.begin(), vector.end(), value), vector.end());
	return vector;
}

std::string vars::getString(std::string name)
{
	if (exists(name))
	{
		if (findStr(name))
		{
			int pos = std::find(stringNames.begin(), stringNames.end(), name) - stringNames.begin();
			return stringValues[pos];
		}
	}
}

double vars::getNumber(std::string name)
{
	if (exists(name))
	{
		if (findNum(name))
		{
			int pos = std::find(doubleNames.begin(), doubleNames.end(), name) - doubleNames.begin();
			return doubleValues[pos];
		}
	}
}

bool vars::getBoolean(std::string name)
{
	if (exists(name))
	{
		if (findBoo(name))
		{
			int pos = std::find(booleanNames.begin(), booleanNames.end(), name) - booleanNames.begin();
			return booleanValues[pos];
		}
	}
}

void vars::deleteVar(std::string name)
{
	if (exists(name))
	{

		if (findStr(name))
		{
			stringValues = vars::remove(stringValues, vars::getString(name));
			stringNames = vars::remove(stringNames, name);
		}
		else if (findNum(name))
		{
			doubleValues = vars::remove(doubleValues, vars::getNumber(name));
			doubleNames = vars::remove(doubleNames, name);
		}
		else if (findBoo(name))
		{
			booleanValues = vars::remove(booleanValues, vars::getBoolean(name));
			booleanNames = vars::remove(booleanNames, name);
		}
	}
	else
	{
		std::cout << "Error variable '" << name << "'does not exit" << std::endl;
	}
}