#include "maths.h"
#include "stdafx.h"

#define PI 3.14159265358979323846

maths::maths()
{
}

int maths::add(std::vector<int> numbers)
{
	int total = 0;
	for (int i : numbers)
	{
		total += i;
	}
	return total;
}

int maths::sub(std::vector<int> numbers)
{
	int total = numbers[0];
	for (int i = 0; i < numbers.size(); i++)
	{
		if (i != 0)
		{
			total = total - numbers[i];
		}
	}
	return total;
}

int maths::mul(std::vector<int> numbers)
{
	int total = numbers[0];
	for (int i = 0; i < numbers.size(); i++)
	{
		if (i != 0)
		{
			total = total * numbers[i];
		}
	}
	return total;
}

int maths::div(std::vector<int> numbers)
{
	int total = numbers[0];
	for (int i = 0; i < numbers.size(); i++)
	{
		if (i != 0)
		{
			total = total / numbers[i];
		}
	}
	return total;
}

int maths::_sin(int number)
{
	int result = sin(maths::DegToRad(number));
	return result;
}

int maths::_cos(int number)
{
	int result = cos(maths::DegToRad(number));
	return result;
}

int maths::_tan(int number)
{
	int result = tan(maths::DegToRad(number));
	return result;
}

int maths::si_(int number)
{
	float result = maths::RadToDeg(asin(number));
	return result;
}

int maths::co_(int number)
{
	float result = maths::RadToDeg(acos(number));
	return result;
}

int maths::ta_(int number)
{
	float result = maths::RadToDeg(atan(number));
	return result;
}

float maths::DegToRad(float deg)
{
	return (deg * PI) / 180;
}

float maths::RadToDeg(float rad)
{
	return (rad * 180) / PI;
}

// sin cos and tan might need to be changed to return floats for higher accuracy

maths::~maths()
{
}
