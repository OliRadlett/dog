// dog.cpp : Defines the entry point for the console application.
// Oli Radlett

#include "stdafx.h"
#include <fstream>
#include <string>
#include "Parser.h"
#include "interpreter.h"

int main(int argc, char* argv[])
{
	std::string lines;

	if (argc > 1)
	{
		std::string fileName(argv[1]);
		std::ifstream t(fileName);
		std::stringstream buffer;
		buffer << t.rdbuf();
		lines = buffer.str();
	}
	else
	{
		std::cout << "No file specified, defaulting to built in test file" << std::endl;
		lines = "OUT Ben is slow;";
	}

	interpreter interpreter_(lines);
	return 0;
}

