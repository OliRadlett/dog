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
			// Anything following the OUT command is outputted
			std::string toOutput = line.substr(4);
			out::out(toOutput);
		}
		else if (command == "ADD")
		{

		}
	}
}


interpreter::~interpreter()
{
}
