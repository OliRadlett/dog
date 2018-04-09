#include "maths.h"
#include "stdafx.h"

#define PI 3.14159265358979323846

maths::maths()
{
}

double maths::add(std::vector<double> numbers)
{
	double total = 0;
	for (double i : numbers)
	{
		total += i;
	}
	return total;
}

double maths::sub(std::vector<double> numbers)
{
	double total = numbers[0];
	for (int i = 0; i < numbers.size(); i++)
	{
		if (i != 0)
		{
			total = total - numbers[i];
		}
	}
	return total;
}

double maths::mul(std::vector<double> numbers)
{
	double total = numbers[0];
	for (int i = 0; i < numbers.size(); i++)
	{
		if (i != 0)
		{
			total = total * numbers[i];
		}
	}
	return total;
}

double maths::div(std::vector<double> numbers)
{
	double total = numbers[0];
	for (int i = 0; i < numbers.size(); i++)
	{
		if (i != 0)
		{
			total = total / numbers[i];
		}
	}
	return total;
}

double maths::_sin(double number)
{
	double result = sin(maths::DegToRad(number));
	return result;
}

double maths::_cos(double number)
{
	double result = cos(maths::DegToRad(number));
	return result;
}

double maths::_tan(double number)
{
	double result = tan(maths::DegToRad(number));
	return result;
}

double maths::si_(double number)
{
	double result = maths::RadToDeg(asin(number));
	return result;
}

double maths::co_(double number)
{
	double result = maths::RadToDeg(acos(number));
	return result;
}

double maths::ta_(double number)
{
	double result = maths::RadToDeg(atan(number));
	return result;
}

double maths::DegToRad(double deg)
{
	return (deg * PI) / 180;
}

double maths::RadToDeg(double rad)
{
	return (rad * 180) / PI;
}

// sin cos and tan might need to be changed to return floats for higher accuracy

maths::~maths()
{
}
