#include "DebugFunctions.h"


DebugFunctions::DebugFunctions()
{
}


DebugFunctions::~DebugFunctions()
{
}

void DebugFunctions::OutputVector(std::vector<std::string> vector)
{
	for (int i = 0; i < vector.size(); i++)
	{
		std::cout << vector[i] << std::endl;
	}
}

void DebugFunctions::OutputVector(std::vector<int> vector)
{
	for (int i = 0; i < vector.size(); i++)
	{
		std::cout << vector[i] << std::endl;
	}
}

void DebugFunctions::OutputVector(std::vector<char> vector)
{
	for (int i = 0; i < vector.size(); i++)
	{
		std::cout << vector[i] << std::endl;
	}
}

void DebugFunctions::OutputVector(std::vector<const char> vector)
{
	for (int i = 0; i < vector.size(); i++)
	{
		std::cout << vector[i] << std::endl;
	}
}
