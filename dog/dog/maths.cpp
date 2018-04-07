#include "maths.h"

#define PI 3.14159265

maths::maths()
{
}

void maths::add(std::vector<int> numbers)
{
	int total = 0;
	for (int i : numbers)
	{
		total += i;
	}
	std::cout << total << std::endl;
}

void maths::sub(std::vector<int> numbers)
{
	int total = numbers[0];
	for (int i = 0; i < numbers.size(); i++)
	{
		if (i != 0)
		{
			total = total - numbers[i];
		}
	}
	std::cout << total << std::endl;
}

void maths::mul(std::vector<int> numbers)
{
	int total = numbers[0];
	for (int i = 0; i < numbers.size(); i++)
	{
		if (i != 0)
		{
			total = total * numbers[i];
		}
	}
	std::cout << total << std::endl;
}

void maths::div(std::vector<int> numbers)
{
	int total = numbers[0];
	for (int i = 0; i < numbers.size(); i++)
	{
		if (i != 0)
		{
			total = total / numbers[i];
		}
	}
	std::cout << total << std::endl;
}

void maths::_sin(int number)
{
	int result = sin(number * PI / 180);
	std::cout << result << std::endl;
}

void maths::_cos(int number)
{
	int result = cos(number * PI / 180);
	std::cout << result << std::endl;
}

void maths::_tan(int number)
{
	int result = tan(number * PI / 180);
	std::cout << result << std::endl;
}

void maths::si_(int number)
{
	float result = asin(number) * 180 / PI;
	std::cout << result << std::endl;
}

void maths::co_(int number)
{
	float result = acos(number) * 180 / PI;
	std::cout << result << std::endl;
}

void maths::ta_(int number)
{
	float result = atan(number) * 180 / PI;
	std::cout << result << std::endl;
}

// sin cos and tan might need to be changed to return floats for higher accuracy

maths::~maths()
{
}
