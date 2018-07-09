#include "interpreter.h"
#include "DebugFunctions.h"

interpreter::interpreter(std::string fileString)
{
	Parser parser;
	std::vector<std::string> lines = parser.Parse(fileString);

	for (int i = 0; i < lines.size(); i++)
	{
		std::string line = lines[i];
		std::vector<std::string> lineTokens = parser.Split(line, " ", true);

		std::string command = lineTokens[0];

		if (command == "OUT")
		{
			interpreter::out(line, parser);
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
		else if (command == "MAN")
		{
			interpreter::man(line);
		}
		else
		{
			std::cout << "'" << command << "' is not a recognised command" << std::endl;
		}
	}
}

void interpreter::out(std::string line, Parser parser)
{
	// Anything following the OUT command is outputted
	std::vector<std::string> parsedLine = parser.Split(line, "'", false);
	if (parsedLine.empty())
	{
		// Probably variable
		outv(line, parser);
	}
	else
	{
		// Probably raw string
		size_t firstQuote = line.find_first_of("'") + 1;
		size_t lastQuote = line.find_last_of("'");
		int lengthOfSubstr = lastQuote - firstQuote;
		std::string rawStr = line.substr(firstQuote, lengthOfSubstr);
		out::out(rawStr);

	}
	//std::string toOutput = line.substr(4);
	//out::out(toOutput);
}

void interpreter::add(std::string line, Parser parser)
{
	// Anything after ADD is to be added
	//std::string numbers = line.substr(4);
	std::string numbers;
	bool containsError = false;
	std::vector<std::string> parsedLine = parser.Split(line, " ", true);
	std::cout << "Parsed " << line << " into: " << std::endl;
	DebugFunctions dbf;
	dbf.OutputVector(parsedLine);
	parsedLine.erase(parsedLine.begin());
	for (std::string operand : parsedLine)
	{
		if (operand.find_first_not_of("0123456789") == std::string::npos)
		{
			// Parse as value
			numbers += " " + operand;
			std::cout << "Interpreted " << operand << " as a value" << std::endl;
		}
		else
		{
			// Parse as variable name
			if (vars::exists(operand))
			{
				// If the variable exists...
				if (vars::getType(operand) == "NUMBER")
				{
					// If the variable is the correct type get the value stored in it
					int value = vars::getNumber(operand);
					// Then apprend the value to the string for parsing
					numbers += " " + std::to_string(value);
					std::cout << "Interpreted " << operand << " as a variable name and read value as " << value << std::endl;
				}
				else
				{
					// Variable is an incorrect type
					containsError = true;
					std::cout << "Error, expected type NUMBER but recieved type: " << vars::getType(operand) << std::endl;
				}
			}
			else
			{
				// Variable does not exist
				containsError = true;
				std::cout << "Error, variable: " << operand << " does not exist" << std::endl;
			}
		}
	}
	if (!containsError)
	{
		// Strip leading whitespace
		numbers = numbers.substr(1, numbers.length());
		std::cout << "Parsed numbers now equals: " << numbers << std::endl;
		double result = maths::add(parser.parseDoubles(numbers));
		out::out(result);
	}
}

void interpreter::sub(std::string line, Parser parser)
{
	// Anything after SUB is to be subtracted
	//std::string numbers = line.substr(4);
	std::string numbers;
	bool containsError = false;
	std::vector<std::string> parsedLine = parser.Split(line, " ", true);
	std::cout << "Parsed " << line << " into: " << std::endl;
	DebugFunctions dbf;
	dbf.OutputVector(parsedLine);
	parsedLine.erase(parsedLine.begin());
	for (std::string operand : parsedLine)
	{
		if (operand.find_first_not_of("0123456789") == std::string::npos)
		{
			// Parse as value
			numbers += " " + operand;
			std::cout << "Interpreted " << operand << " as a value" << std::endl;
		}
		else
		{
			// Parse as variable name
			if (vars::exists(operand))
			{
				// If the variable exists...
				if (vars::getType(operand) == "NUMBER")
				{
					// If the variable is the correct type get the value stored in it
					int value = vars::getNumber(operand);
					// Then apprend the value to the string for parsing
					numbers += " " + std::to_string(value);
					std::cout << "Interpreted " << operand << " as a variable name and read value as " << value << std::endl;
				}
				else
				{
					// Variable is an incorrect type
					containsError = true;
					std::cout << "Error, expected type NUMBER but recieved type: " << vars::getType(operand) << std::endl;
				}
			}
			else
			{
				// Variable does not exist
				containsError = true;
				std::cout << "Error, variable: " << operand << " does not exist" << std::endl;
			}
		}
	}
	if (!containsError)
	{
		// Strip leading whitespace
		numbers = numbers.substr(1, numbers.length());
		std::cout << "Parsed numbers now equals: " << numbers << std::endl;
		double result = maths::sub(parser.parseDoubles(numbers));
		out::out(result);
	}
}

void interpreter::mul(std::string line, Parser parser)
{
	// Anything after MUL is to be multiplied
	//std::string numbers = line.substr(4);
	std::string numbers;
	bool containsError = false;
	std::vector<std::string> parsedLine = parser.Split(line, " ", true);
	std::cout << "Parsed " << line << " into: " << std::endl;
	DebugFunctions dbf;
	dbf.OutputVector(parsedLine);
	parsedLine.erase(parsedLine.begin());
	for (std::string operand : parsedLine)
	{
		if (operand.find_first_not_of("0123456789") == std::string::npos)
		{
			// Parse as value
			numbers += " " + operand;
			std::cout << "Interpreted " << operand << " as a value" << std::endl;
		}
		else
		{
			// Parse as variable name
			if (vars::exists(operand))
			{
				// If the variable exists...
				if (vars::getType(operand) == "NUMBER")
				{
					// If the variable is the correct type get the value stored in it
					int value = vars::getNumber(operand);
					// Then apprend the value to the string for parsing
					numbers += " " + std::to_string(value);
					std::cout << "Interpreted " << operand << " as a variable name and read value as " << value << std::endl;
				}
				else
				{
					// Variable is an incorrect type
					containsError = true;
					std::cout << "Error, expected type NUMBER but recieved type: " << vars::getType(operand) << std::endl;
				}
			}
			else
			{
				// Variable does not exist
				containsError = true;
				std::cout << "Error, variable: " << operand << " does not exist" << std::endl;
			}
		}
	}
	if (!containsError)
	{
		// Strip leading whitespace
		numbers = numbers.substr(1, numbers.length());
		std::cout << "Parsed numbers now equals: " << numbers << std::endl;
		double result = maths::mul(parser.parseDoubles(numbers));
		out::out(result);
	}
}

void interpreter::div(std::string line, Parser parser)
{
	// Anything after DIV is to be divided
	//std::string numbers = line.substr(4);
	std::string numbers;
	bool containsError = false;
	std::vector<std::string> parsedLine = parser.Split(line, " ", true);
	std::cout << "Parsed " << line << " into: " << std::endl;
	DebugFunctions dbf;
	dbf.OutputVector(parsedLine);
	parsedLine.erase(parsedLine.begin());
	for (std::string operand : parsedLine)
	{
		if (operand.find_first_not_of("0123456789") == std::string::npos)
		{
			// Parse as value
			numbers += " " + operand;
			std::cout << "Interpreted " << operand << " as a value" << std::endl;
		}
		else
		{
			// Parse as variable name
			if (vars::exists(operand))
			{
				// If the variable exists...
				if (vars::getType(operand) == "NUMBER")
				{
					// If the variable is the correct type get the value stored in it
					int value = vars::getNumber(operand);
					// Then apprend the value to the string for parsing
					numbers += " " + std::to_string(value);
					std::cout << "Interpreted " << operand << " as a variable name and read value as " << value << std::endl;
				}
				else
				{
					// Variable is an incorrect type
					containsError = true;
					std::cout << "Error, expected type NUMBER but recieved type: " << vars::getType(operand) << std::endl;
				}
			}
			else
			{
				// Variable does not exist
				containsError = true;
				std::cout << "Error, variable: " << operand << " does not exist" << std::endl;
			}
		}
	}
	if (!containsError)
	{
		// Strip leading whitespace
		numbers = numbers.substr(1, numbers.length());
		std::cout << "Parsed numbers now equals: " << numbers << std::endl;
		double result = maths::div(parser.parseDoubles(numbers));
		out::out(result);
	}
}

void interpreter::_sin(std::string line)
{
	// The number following SIN is used in the sin function
	std::string number = line.substr(4);
	bool containsError = false;
	if (number.find_first_not_of("0123456789") != std::string::npos)
	{
		// Probably a variable
		if (vars::exists(number))
		{
			if (vars::getType(number) == "NUMBER")
			{
				// Replace var name with var value
				number = std::to_string(vars::getNumber(number));
			}
			else
			{
				// Variable is an incorrect type
				containsError = true;
				std::cout << "Error, expected type NUMBER but recieved type: " << vars::getType(number) << std::endl;
			}
		}
		else
		{
			// Variable does not exist
			containsError = true;
			std::cout << "Error, variable: " << number << " does not exist" << std::endl;
		}
	}
	if (!containsError)
	{
		double result = maths::_sin(std::stod(number));
		out::out(result);
	}
}

void interpreter::_cos(std::string line)
{
	// The number following COS is used in the cos function
	std::string number = line.substr(4);
	bool containsError = false;
	if (number.find_first_not_of("0123456789") != std::string::npos)
	{
		// Probably a variable
		if (vars::exists(number))
		{
			if (vars::getType(number) == "NUMBER")
			{
				// Replace var name with var value
				number = std::to_string(vars::getNumber(number));
			}
			else
			{
				// Variable is an incorrect type
				containsError = true;
				std::cout << "Error, expected type NUMBER but recieved type: " << vars::getType(number) << std::endl;
			}
		}
		else
		{
			// Variable does not exist
			containsError = true;
			std::cout << "Error, variable: " << number << " does not exist" << std::endl;
		}
	}
	if (!containsError)
	{
		double result = maths::_cos(std::stod(number));
		out::out(result);
	}
}

void interpreter::_tan(std::string line)
{
	// The number following TAN is used in the tan function
	std::string number = line.substr(4);
	bool containsError = false;
	if (number.find_first_not_of("0123456789") != std::string::npos)
	{
		// Probably a variable
		if (vars::exists(number))
		{
			if (vars::getType(number) == "NUMBER")
			{
				// Replace var name with var value
				number = std::to_string(vars::getNumber(number));
			}
			else
			{
				// Variable is an incorrect type
				containsError = true;
				std::cout << "Error, expected type NUMBER but recieved type: " << vars::getType(number) << std::endl;
			}
		}
		else
		{
			// Variable does not exist
			containsError = true;
			std::cout << "Error, variable: " << number << " does not exist" << std::endl;
		}
	}
	if (!containsError)
	{
		double result = maths::_tan(std::stod(number));
		out::out(result);
	}
}

void interpreter::_isin(std::string line)
{
	// The number following SINi is used in the inverse sin function
	std::string number = line.substr(5);
	bool containsError = false;
	if (number.find_first_not_of("0123456789") != std::string::npos)
	{
		// Probably a variable
		if (vars::exists(number))
		{
			if (vars::getType(number) == "NUMBER")
			{
				// Replace var name with var value
				number = std::to_string(vars::getNumber(number));
			}
			else
			{
				// Variable is an incorrect type
				containsError = true;
				std::cout << "Error, expected type NUMBER but recieved type: " << vars::getType(number) << std::endl;
			}
		}
		else
		{
			// Variable does not exist
			containsError = true;
			std::cout << "Error, variable: " << number << " does not exist" << std::endl;
		}
	}
	if (!containsError)
	{
		double result = maths::_isin(std::stod(number));
		out::out(result);
	}
}

void interpreter::_icos(std::string line)
{
	// The number following COSi is used in the inverse cos function
	std::string number = line.substr(5);
	bool containsError = false;
	if (number.find_first_not_of("0123456789") != std::string::npos)
	{
		// Probably a variable
		if (vars::exists(number))
		{
			if (vars::getType(number) == "NUMBER")
			{
				// Replace var name with var value
				number = std::to_string(vars::getNumber(number));
			}
			else
			{
				// Variable is an incorrect type
				containsError = true;
				std::cout << "Error, expected type NUMBER but recieved type: " << vars::getType(number) << std::endl;
			}
		}
		else
		{
			// Variable does not exist
			containsError = true;
			std::cout << "Error, variable: " << number << " does not exist" << std::endl;
		}
	}
	if (!containsError)
	{
		double result = maths::_icos(std::stod(number));
		out::out(result);
	}
}

void interpreter::_itan(std::string line)
{
	// The number following TANi is used in the inverse tan function
	std::string number = line.substr(5);
	bool containsError = false;
	if (number.find_first_not_of("0123456789") != std::string::npos)
	{
		// Probably a variable
		if (vars::exists(number))
		{
			if (vars::getType(number) == "NUMBER")
			{
				// Replace var name with var value
				number = std::to_string(vars::getNumber(number));
			}
			else
			{
				// Variable is an incorrect type
				containsError = true;
				std::cout << "Error, expected type NUMBER but recieved type: " << vars::getType(number) << std::endl;
			}
		}
		else
		{
			// Variable does not exist
			containsError = true;
			std::cout << "Error, variable: " << number << " does not exist" << std::endl;
		}
	}
	if (!containsError)
	{
		double result = maths::_itan(std::stod(number));
		out::out(result);
	}
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
	bool value;
	// Not elegant but idk
	if (parsedLine[1] == "true")
	{
		value = true;
	}
	else if (parsedLine[1] == "false")
	{
		value = false;
	}
	vars::InitBoolean(parsedLine[0], value);
}

void interpreter::outv(std::string line, Parser parser)
{
	// varName always follows OUTV
	std::string varName = line.substr(4);
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
			int varValue = vars::getBoolean(varName);
			// There's probably a nicer way of doing this but we need to get a String representation of the bool instead of 0-1
			switch (varValue)
			{
			// Not sure why out::out doesnt work but std::cout seems to :thinking:
			case 0:
				std::cout << "false" << std::endl;
				break;
			case 1:
				std::cout << "true" << std::endl;
				break;
			}
		}
	}
	else
	{
		std::cout << "Variable '" << varName << "' does not exist" << std::endl;
	}
}

void interpreter::man(std::string line)
{
	// Anything after MAN is the command
	std::string command = line.substr(4);
	man::man(command);
}

interpreter::~interpreter()
{
}
