#pragma once
#include <string>
#include <vector>
#include <iostream>
#include <math.h>
#include "out.h"
#include "DebugFunctions.h"

class maths
{
public:
	maths();
	~maths();
	// Aggghhhhhh!!!!
	// FIX ALL THIS STATIC ACCESS!!!
	static void add(std::vector<int> numbers);
	static void add(std::vector<std::string> vars);
	static void sub(std::vector<int> numbers);
	static void sub(std::vector<std::string> vars);
	static void mul(std::vector<int> numbers);
	static void mul(std::vector<std::string> vars);
	static void div(std::vector<int> numbers);
	static void div(std::vector<std::string> vars);
	static void _sin(int number);
	static void _sin(std::string string);
	static void _cos(int number);
	static void _cos(std::string string);
	static void _tan(int number);
	static void _tan(std::string string);
	static void si_(int number);
	static void si_(std::string string);
	static void co_(int number);
	static void co_(std::string string);
	static void ta_(int number);
	static void ta_(std::string string);
};

