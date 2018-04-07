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
		lines = "OUT Test string;OUT Another Test String;ADD 1 2 3 4 5;SUB 5 4 3 2 1; MUL 2 2; DIV 10 2; SIN 90; COS 90; TAN 1; SI_ 1; CO_ 0.5; TA_ 1;";
	}

	interpreter interpreter_(lines);
	return 0;
}

