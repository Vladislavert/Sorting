#include "Console.hpp"

#include "SortManager.hpp"
#include <boost/algorithm/string.hpp>

#include "Sorting.hpp"

bool Console::startConsole()
{
	SortManager sortManager;

	sortManager.start();
	return false;
}
