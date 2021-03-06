#pragma once
#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <ctype.h>
#include "Parser.h"
#include "out.h"
#include "maths.h"
#include "vars.h"
#include "set.h"
#include "man.h"

class interpreter
{
public:
	interpreter(std::string fileString);
	~interpreter();
private:
	void out(std::string line, Parser parser, bool conditional);
	void add(std::string line, Parser parser);
	void sub(std::string line, Parser parser);
	void mul(std::string line, Parser parser);
	void div(std::string line, Parser parser);
	void _sin(std::string line);
	void _cos(std::string line);
	void _tan(std::string line);
	void _isin(std::string line);
	void _icos(std::string line);
	void _itan(std::string line);
	void string(std::string line, Parser parser);
	void number(std::string line, Parser parser);
	void boolean(std::string line, Parser parser);
	void outv(std::string line, Parser parser);
	void man(std::string line);
	void in(std::string line, Parser parser);
	bool containsConditional(std::string line);
	bool conditionalEvaluates(std::vector<std::string> conditional);
};