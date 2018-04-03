#include "add.h"


add::add(std::vector<int> numbers)
{
	int total = 0;
	for (int i = 0; i < numbers.size(); i++)
	{
		total += numbers[i];
	}
	std::string totalStr = std::string("" + total);
	out::out(totalStr);
}


add::~add()
{
}
