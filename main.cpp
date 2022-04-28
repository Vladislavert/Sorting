#include <sstream>
#include <vector>
#include <boost/algorithm/string.hpp>

#include "Console.hpp"

#include "Sorting.hpp"

int main()
{
//	Console console;
//	while (console.startConsole()) {}

	// test binary heap

//	int a[] = {1, 10, 5, 13};
//	int a[] = {1, 6, 5, 10};
	int a[] = {1, 7, 5, 10, 6, 8, 213, 3, -10};


	std::cout << "array" << std::endl;
	sort::display(std::begin(a), std::end(a));

//	sort::binaryHeap(std::begin(a), std::end(a));
	sort::binaryHeap(std::begin(a), std::end(a), true);
	std::cout << "sort array" << std::endl;
	sort::display(std::begin(a), std::end(a));

	return (0);
}