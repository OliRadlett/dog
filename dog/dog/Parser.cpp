#include "Parser.h"

Parser::Parser()
{

}

std::vector<std::string>Parser::Parse(std::string fileString)
{
	std::vector < std::string> lines = SplitFile(fileString);
	return lines;
}

std::vector<std::string> Parser::SplitFile(std::string fileString)
{
	//std::string testString = "ADD 1 2; SUB 2 1;                MUL 2 3;OUT 5;";
	std::vector<std::string> lines;

	size_t pos = 0;
	std::string token;

	while ((pos = fileString.find(";")) != std::string::npos)
	{
		token = fileString.substr(0, pos);
		lines.push_back(token);
		fileString.erase(0, pos + 1);
		
		while (fileString[0] == ' ')
		{
			fileString.erase(0, 1);
		}
	}

	return lines;
}

Parser::~Parser()
{
}