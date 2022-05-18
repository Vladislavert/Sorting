#include <sstream>
#include <vector>
#include <boost/algorithm/string.hpp>

#include "Console.hpp"

#include "Sorting.hpp"
#include "Searching.hpp"


template<class Iterator>
int printIndex(Iterator begin, Iterator index)
{
	int retIndex = 0;

	retIndex = std::distance(begin, index);
	return (retIndex);
}

bool mypredicate (int i, int j) {
	return (i==j);
}

int main()
{
//	Console console;
//	while (console.startConsole()) {}

	// test binary heap

//	int a[] = {1, 10, 5, 13};
//	int a[] = {1, 6, 5, 10};
//	std::vector<int> a = {1, 7, 5, 10, 6, 8, 213, 3, -10};
//	std::vector<int> k = {-1, 1, 90, 213, 5};
//
//	std::cout << "linear" << std::endl;
//	for (auto i : k)
//	{
//		std::cout << "lib:" << std::endl;
////		std::cout << std::search(a.begin(), a.end(), i, mypredicate) << std::endl;
//		std::cout << "user lib:" << std::endl;
//		std::cout << search::linearSearch(a.begin(), a.end(), i) << std::endl;
//	}
//	std::cout << "binary search" << std::endl;
//	std::sort(a.begin(), a.end(), std::less<>());
//	for (auto i : k)
//	{
//		std::cout << "lib:" << std::endl;
//		std::cout << std::binary_search(a.begin(), a.end(), i) << std::endl;
//		std::cout << "user lib:" << std::endl;
//		std::cout << search::binarySearch(a.begin(), a.end(), i) << std::endl;
//	}

	return (0);
}