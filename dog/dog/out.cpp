#include "out.h"


out::out(std::string toOutput)
{
	std::cout << toOutput << std::endl;
}

out::out(double toOutput)
{
	std::cout << toOutput << std::endl;
}

out::~out()
{
}
