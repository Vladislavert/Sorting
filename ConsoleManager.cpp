#include "ConsoleManager.hpp"

void ConsoleManager::printDataType()
{
	std::cout << "data type:" << std::endl;
	std::cout << "1 - INTEGER" << std::endl;
	std::cout << "2 - DOUBLE" << std::endl;
	std::cout << "3 - STRING" << std::endl;
	std::cout << "4 - DATE" << std::endl;
}

void ConsoleManager::commandNotFound(const std::string& cmd)
{
	std::cout << "command " << cmd << ": not found" << std::endl;
}