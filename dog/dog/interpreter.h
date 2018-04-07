#pragma once
#include <string>
#include <vector>
#include <iostream>
#include "Parser.h"
#include "out.h"
#include "maths.h"

class interpreter
{
public:
	interpreter(std::string fileString);
	~interpreter();
private:
	void out(std::string line);
	void add(std::string line, Parser parser);
	void sub(std::string line, Parser parser);
	void mul(std::string line, Parser parser);
	void div(std::string line, Parser parser);
	void _sin(std::string line);
	void _cos(std::string line);
	void _tan(std::string line);
	void si_(std::string line);
	void co_(std::string line);
	void ta_(std::string line);
};