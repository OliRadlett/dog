#include "out.h"


out::out(std::string toOutput)
{
	std::cout << toOutput << std::endl;
}

out::out(int toOutput)
{
	std::cout << toOutput << std::endl;
}

out::~out()
{
}
