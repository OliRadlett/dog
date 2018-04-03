#include "interpreter.h"


interpreter::interpreter(std::string fileString)
{
	Parser parser;
	std::vector<std::string> lines = parser.Parse(fileString);

	for (int i = 0; i < lines.size(); i++)
	{
		std::string line = lines[i];
		// Command is always first 3 characters of the line
		std::string command = line.substr(0, 3);

		if (command == "OUT")
		{
			interpreter::out(line);
		}
		else if (command == "ADD")
		{
			interpreter::add(line);
		}
	}
}

void interpreter::out(std::string line)
{
	// Anything following the OUT command is outputted
	std::string toOutput = line.substr(4);
	out::out(toOutput);
}

void interpreter::add(std::string line) {
	// Anything after ADD is to be added
	std::string numbers = line.substr(4);
	parser::parseInts(numbers);
}


interpreter::~interpreter()
{
}
