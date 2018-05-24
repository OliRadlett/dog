#pragma once
#include <string>
#include <vector>
#include <iostream>
#include "out.h"
#include "DebugFunctions.h"
#include <cmath>
#include <iomanip> 
#include <cstdlib>

class maths
{
public:
	maths();
	~maths();
	static double add(std::vector<double> numbers);
	static double add(std::vector<std::string> vars);
	static double sub(std::vector<double> numbers);
	static double sub(std::vector<std::string> vars);
	static double mul(std::vector<double> numbers);
	static double mul(std::vector<std::string> vars);
	static double div(std::vector<double> numbers);
	static double div(std::vector<std::string> vars);
	static double _sin(double number);
	static double _sin(std::string string);
	static double _cos(double number);
	static double _cos(std::string string);
	static double _tan(double number);
	static double _tan(std::string string);
	static double _isin(double number);
	static double _isin(std::string string);
	static double _icos(double number);
	static double _icos(std::string string);
	static double _itan(double number);
	static double _itan(std::string string);
	static double DegToRad(double deg);
	static double RadToDeg(double rad);
	static double round(double number);
};

