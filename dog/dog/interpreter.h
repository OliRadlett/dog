#pragma once
#include <string>
#include <vector>
#include <iostream>
#include "Parser.h"
#include "out.h"
#include "add.h"

class interpreter
{
public:
	interpreter(std::string fileString);
	~interpreter();
private:
	void out(std::string line);
	void add(std::string line);
};

