#include "maths.h"
#include "stdafx.h"

#define PI 3.14159265358979323846264338327950288

// 0.0000000000000000000000000000000000000000000000000000001 != 0
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
	double result = round(sin(maths::DegToRad(number)) * 1000.0) / 1000.0;
	return result;
}

double maths::_cos(double number)
{
	double result = round(cos(maths::DegToRad(number)) * 1000.0) / 1000.0;
	//if (result == )
	return result;
}

double maths::_tan(double number)
{
	double result = round(tan(maths::DegToRad(number)) * 1000.0) / 1000.0;
	return result;
}

double maths::_isin(double number)
{
	double result = round(maths::RadToDeg(asin(number)) * 1000.0) / 1000.0;
	return result;
}

double maths::_icos(double number)
{
	double result = round(maths::RadToDeg(acos(number)) * 1000.0) / 1000.0;
	return result;
}

double maths::_itan(double number)
{
	double result = round(maths::RadToDeg(atan(number)) * 1000.0) / 1000.0;
	return result;
}

double maths::DegToRad(double deg)
{
	return (deg * PI / 180);
}

double maths::RadToDeg(double rad)
{
	return (rad * 180 / PI);
}

double maths::round(double val)
{
	if (val < 0) return ceil(val - 0.5);
	return floor(val + 0.5);
}

maths::~maths()
{
}
