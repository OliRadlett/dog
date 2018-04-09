#pragma once
#include <string>
#include <vector>
#include <iostream>
#include "out.h"
#include "DebugFunctions.h"
#include <math.h>
#define _USE_MATH_DEFINES

class maths
{
public:
	maths();
	~maths();
	// Aggghhhhhh!!!!
	// FIX ALL THIS STATIC ACCESS!!!
	// Also floats might be an idea
	static int add(std::vector<int> numbers);
	static int add(std::vector<std::string> vars);
	static int sub(std::vector<int> numbers);
	static int sub(std::vector<std::string> vars);
	static int mul(std::vector<int> numbers);
	static int mul(std::vector<std::string> vars);
	static int div(std::vector<int> numbers);
	static int div(std::vector<std::string> vars);
	static int _sin(int number);
	static int _sin(std::string string);
	static int _cos(int number);
	static int _cos(std::string string);
	static int _tan(int number);
	static int _tan(std::string string);
	static int si_(int number);
	static int si_(std::string string);
	static int co_(int number);
	static int co_(std::string string);
	static int ta_(int number);
	static int ta_(std::string string);
};

