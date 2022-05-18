#include "Console.hpp"

#include "SortManager.hpp"
#include <boost/algorithm/string.hpp>

#include "Sorting.hpp"
#include "SearchManager.hpp"

bool Console::startConsole(const std::string& typeProgram)
{
	if (typeProgram == "sort")
	{
		SortManager sortManager;

		sortManager.start();
	}
	else if (typeProgram == "search")
	{
		SearchManager searchManager;

		searchManager.start();
	}
	else if (typeProgram == "exit")
	{
		return false;
	}
	else
	{
		std::cout << typeProgram << ": not found" << std::endl;
	}

	return false;
}
