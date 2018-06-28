#include "man.h"


man::man(std::string command)
{
	if (command == "//")
	{
		std::cout << "Defines a comment" << std::endl;
	}
	else if (command == "OUT")
	{
		std::cout << "Outputs either a raw String or the contents of a variable of any type - Usage: OUT 'Hello world'; Returns Hello world, OUT myString; Returns the value stored in the myString String" << std::endl;
	}
	else if (command == "ADD")
	{
		std::cout << "Add a series of numbers together - Usage: ADD 1 2 3; Returns 6" << std::endl;
	}
	else if (command == "SUB")
	{
		std::cout << "Subtracts a series of numbers away from each other - Usage: SUB 3 2 1; Returns 0" << std::endl;
	}
	else if (command == "MUL")
	{
		std::cout << "Multiplies a series of numbers together - Usage: MUL 2 5; Returns 10" << std::endl;
	}
	else if (command == "DIV")
	{
		std::cout << "Divides a series of numbers - Usage: DIV 10 2; Returns 5" << std::endl;
	}
	else if (command == "SIN")
	{
		std::cout << "Calculates the Sine of a number in degrees - Usage: SIN 90; Returns 1" << std::endl;
	}
	else if (command == "COS")
	{
		std::cout << "Calculates the Cosine of a number in degrees - Usage: COS 90; Returns 0" << std::endl;
	}
	else if (command == "TAN")
	{
		std::cout << "Calculates the Tangent of a number in degrees - Usage: TAN 45; Returns 1" << std::endl;
	}
	else if (command == "SINi")
	{
		std::cout << "Calculates the inverse Sine of a number in degrees - Usage: SINi 1; Returns 90" << std::endl;
	}
	else if (command == "COSi")
	{
		std::cout << "Calculates the inverse Cosine of a number in degrees - Usage: SINi 0; Returns 90" << std::endl;
	}
	else if (command == "TANi")
	{
		std::cout << "Calculates the inverse Tangent of a number in degrees - Usage: TANi 1; Returns 45" << std::endl;
	}
	else if (command == "STRING")
	{
		std::cout << "Defines a new variable of type STRING - Usage: STRING myString Hello World;" << std::endl;
	}
	else if (command == "NUMBER")
	{
		std::cout << "Defines a new variable of type NUMBER - Usage: NUMBER myNumber 12;" << std::endl;
	}
	else if (command == "BOOLEAN")
	{
		std::cout << "Defines a new variable of type BOOLEAN - Usage: BOOLEAN myBoolean false;" << std::endl;
	}
	else if (command == "MAN")
	{
		std::cout << "Outputs the manual page for each command - Usage: MAN ADD; Returns: Add a series of numbers together - Usage: ADD 1 2 3; Returns 6" << std::endl;
	}
}


man::~man()
{
}