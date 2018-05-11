// dog.cpp : Defines the entry point for the console application.
// Oli Radlett

#include "stdafx.h"
#include <fstream>
#include <string>
#include <sys\stat.h>
#include "Parser.h"
#include "interpreter.h"

// FileExists method from -
// https://stackoverflow.com/questions/12774207/fastest-way-to-check-if-a-file-exist-using-standard-c-c11-c
inline bool FileExists(const std::string& name)
{
	struct stat buffer;
	return (stat(name.c_str(), &buffer) == 0);
}

int main(int argc, char* argv[])
{
	std::string lines;
	if (argc > 1)
	{
		if (FileExists(argv[1]))
		{
			std::string fileName(argv[1]);
			std::ifstream t(fileName);
			std::stringstream buffer;
			buffer << t.rdbuf();
			lines = buffer.str();
		}
		else
		{
			std::cout << "Error: File not found" << std::endl;
			return 0;
		}
	}
	else
	{
		std::cout << "No file specified" << std::endl;
		return 0;
		//lines = "OUT Test string;OUT Another Test String;ADD 1 2 3 4 5;SUB 5 4 3 2 1; MUL 2 2; DIV 10 2; SIN 90; COS 90; TAN 1; SI_ 1; CO_ 0.5; TA_ 1;";
	}

	interpreter interpreter_(lines);

	return 0;
}

