#pragma once

#include <string>
#include <vector>

class set
{
public:
	set();
	~set();
	static void set_(std::string name, std::string value);
	static void set_(std::string name, double value);
};