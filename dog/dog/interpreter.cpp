#include "interpreter.h"


interpreter::interpreter(std::string fileString)
{
	Parser parser;
	std::vector<std::string> lines = parser.Parse(fileString);

	for (int i = 0; i < lines.size(); i++)
	{
		std::string line = lines[i];
		std::vector<std::string> lineTokens = parser.Split(line, " ", true);

		std::string command = lineTokens[0];

		/*if (command == "//")
		{
			// Skip line
			continue;
		}
		else */if (command == "OUT")
		{
			interpreter::out(line);
		}
		else if (command == "ADD")
		{
			interpreter::add(line, parser);
		}
		else if (command == "SUB")
		{
			interpreter::sub(line, parser);
		}
		else if (command == "MUL")
		{
			interpreter::mul(line, parser);
		}
		else if (command == "DIV")
		{
			interpreter::div(line, parser);
		}
		else if (command == "SIN")
		{
			interpreter::_sin(line);
		}
		else if (command == "COS")
		{
			interpreter::_cos(line);
		}
		else if (command == "TAN")
		{
			interpreter::_tan(line);
		}
		else if (command == "SINi")
		{
			interpreter::_isin(line);
		}
		else if (command == "COSi")
		{
			interpreter::_icos(line);
		}
		else if (command == "TANi")
		{
			interpreter::_itan(line);
		}
		else if (command == "STRING")
		{
			interpreter::string(line, parser);
		}
		else if (command == "NUMBER")
		{
			interpreter::number(line, parser);
		}
		else if (command == "BOOLEAN")
		{
			interpreter::boolean(line, parser);
		}
		else if (command == "TEST")
		{
			std::cout << "4 character operand test" << std::endl;
		}
		else if (command == "OUTV")
		{
			interpreter::outv(line, parser);
		}
		else
		{
			std::cout << "'" << command << "' is not a recognised command" << std::endl;
		}
	}
}

void interpreter::out(std::string line)
{
	// Anything following the OUT command is outputted
	std::string toOutput = line.substr(4);
	out::out(toOutput);
}

void interpreter::add(std::string line, Parser parser)
{
	// Anything after ADD is to be added
	std::string numbers = line.substr(4);
	double result = maths::add(parser.parseDoubles(numbers));
	out::out(result);
}

void interpreter::sub(std::string line, Parser parser)
{
	// Anything after SUB is to be subtracted
	std::string numbers = line.substr(4);
	double result = maths::sub(parser.parseDoubles(numbers));
	out::out(result);
}

void interpreter::mul(std::string line, Parser parser)
{
	// Anything after MUL is to be multipled
	std::string numbers = line.substr(4);
	double result = maths::mul(parser.parseDoubles(numbers));
	out::out(result);
}

void interpreter::div(std::string line, Parser parser)
{
	// Anything after DIV is to be divided
	std::string numbers = line.substr(4);
	double result = maths::div(parser.parseDoubles(numbers));
	out::out(result);
}

void interpreter::_sin(std::string line)
{
	// The number following SIN is used in the sin function
	std::string number = line.substr(4);
	double result = maths::_sin(std::stod(number));
	out::out(result);
}

void interpreter::_cos(std::string line)
{
	// The number following COS is used in the cos function
	std::string number = line.substr(4);
	double result = maths::_cos(std::stod(number));
	out::out(result);
}

void interpreter::_tan(std::string line)
{
	// The number following TAN is used in the tan function
	std::string number = line.substr(4);
	double result = maths::_tan(std::stod(number));
	out::out(result);
}

void interpreter::_isin(std::string line)
{
	// The number following SINi is used in the inverse sin function
	std::string number = line.substr(5);
	double result = maths::_isin(std::stod(number));
	out::out(result);
}

void interpreter::_icos(std::string line)
{
	// The number following COSi is used in the inverse cos function
	std::string number = line.substr(5);
	double result = maths::_icos(std::stod(number));
	out::out(result);
}

void interpreter::_itan(std::string line)
{
	// The number following TANi is used in the inverse tan function
	std::string number = line.substr(5);
	double result = maths::_itan(std::stod(number));
	out::out(result);
}

void interpreter::string(std::string line, Parser parser)
{
	// Parse line into name and value
	std::vector<std::string> parsedLine = parser.ParseInitString(line);
	vars::InitString(parsedLine[0], parsedLine[1]);
}

void interpreter::number(std::string line, Parser parser)
{
	// Parse line into name and value
	std::vector<std::string> parsedLine = parser.ParseInitDouble(line);
	// Str to double to Str to double doesn't seem to good...
	vars::InitDouble(parsedLine[0], std::stod(parsedLine[1]));
}

void interpreter::boolean(std::string line, Parser parser)
{
	// Parse line into name and value
	std::vector<std::string> parsedLine = parser.ParseInitBoolean(line);
	// Str to bool to Str to bool doesn't seem to good...
	bool value;
	std::istringstream(parsedLine[1]) >> value;
	vars::InitBoolean(parsedLine[0], value);
}

void interpreter::outv(std::string line, Parser parser)
{
	// varName always follows OUTV
	std::string varName = line.substr(5);
	// Check if var exists
	bool exists = vars::exists(varName);
	if (exists)
	{
		std::string type = vars::getType(varName);
		if (type == "STRING")
		{
			std::string varValue = vars::getString(varName);
			out::out(varValue);
		}
		else if (type == "NUMBER")
		{
			double varValue = vars::getNumber(varName);
			out::out(varValue);
		}
		else if (type == "BOOLEAN")
		{
			bool varValue = vars::getBoolean(varName);
			out::out(varValue);
		}
	}
	else
	{
		std::cout << "Variable '" << varName << "' does not exist";
	}
}

interpreter::~interpreter()
{
}
