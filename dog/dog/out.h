#pragma once
#include <string>
#include <iostream>
#include <iomanip>

class out
{
public:
	out(std::string toOutput);
	out(double toOutput);
	~out();
};
