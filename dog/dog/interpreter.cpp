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
		else if (command == "SI_")
		{
			interpreter::si_(line);
		}
		else if (command == "CO_")
		{
			interpreter::co_(line);
		}
		else if (command == "TA_")
		{
			interpreter::ta_(line);
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
	int result = maths::add(parser.parseInts(numbers));
	out::out(result);
}

void interpreter::sub(std::string line, Parser parser)
{
	// Anything after SUB is to be subtracted
	std::string numbers = line.substr(4);
	int result = maths::sub(parser.parseInts(numbers));
	out::out(result);
}

void interpreter::mul(std::string line, Parser parser)
{
	// Anything after MUL is to be multipled
	std::string numbers = line.substr(4);
	int result = maths::mul(parser.parseInts(numbers));
	out::out(result);
}

void interpreter::div(std::string line, Parser parser)
{
	// Anything after DIV is to be divided
	std::string numbers = line.substr(4);
	int result = maths::div(parser.parseInts(numbers));
	out::out(result);
}

void interpreter::_sin(std::string line)
{
	// The number following SIN is used in the sin function
	std::string number = line.substr(4);
	int result = maths::_sin(std::stoi(number));
	out::out(result);
}

void interpreter::_cos(std::string line)
{
	// The number following COS is used in the cos function
	std::string number = line.substr(4);
	int result = maths::_cos(std::stoi(number));
	out::out(result);
}

void interpreter::_tan(std::string line)
{
	// The number following TAN is used in the tan function
	std::string number = line.substr(4);
	int result = maths::_tan(std::stoi(number));
	out::out(result);
}

void interpreter::si_(std::string line)
{
	// The number following SI_ is used in the inverse sin function
	std::string number = line.substr(4);
	int result = maths::si_(std::stoi(number));
	out::out(result);
}

void interpreter::co_(std::string line)
{
	// The number following CO_ is used in the inverse cos function
	std::string number = line.substr(4);
	int result = maths::co_(std::stoi(number));
	out::out(result);
}

void interpreter::ta_(std::string line)
{
	// The number following TA_ is used in the inverse tan function
	std::string number = line.substr(4);
	int result = maths::ta_(std::stoi(number));
	out::out(result);
}

// Decimals might not be supported (investigation needed)

interpreter::~interpreter()
{
}
