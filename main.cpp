#include <sstream>
#include <vector>
#include <boost/algorithm/string.hpp>

#include "Sorting.hpp"

void console()
{	
	std::string typeSort;
	std::string orderBy;
	std::cout << "enter sort type and sort order" << std::endl;
	std::cout << "1 - bubbleSort" << std::endl;
	std::cout << "2 - insertionSort" << std::endl;
	std::cout << "3 - selectionSort" << std::endl;
	getline(std::cin, typeSort);
	std::vector<std::string> v1;
	std::string str;
	int length(0);

	if (typeSort == "1")
	{
		std::cout << "bubble sort:" << std::endl;
	}
	else if (typeSort == "2")
	{
		std::cout << "insertion sort:" << std::endl;
	}
	else
	{
		std::cout << "selection sort:" << std::endl;
	}
	std::cout << "order by" << std::endl;
	std::cout << "1 - ASC" << std::endl; // ascent(восхождение)
	std::cout << "2 - DESC" << std::endl; // descent(спуск)
	getline(std::cin, orderBy);
	// std::cout << "is number" << std::endl;
	// std::cout << "1 - NO" << std::endl; // ascent(восхождение)
	// std::cout << "2 - YES" << std::endl; // descent(спуск)
	std::cout << "enter data:" << std::endl;
    getline(std::cin, str);
	int i = 0;
	while(i != str.size())
	{
		i++;
		if (str[i] == ' ')
			length++;
	}
	length++;
	std::vector<std::string> strVector;
	boost::split(strVector, str, boost::is_any_of(" "));

	if (typeSort == "1" && orderBy == "1")
	{
		std::cout << "bubble sort(ascent):" << std::endl;
		sort::bubbleSort(strVector.begin(), strVector.end(), true);
	}
	else if (typeSort == "1" && orderBy == "2")
	{
		std::cout << "bubble sort(descent):" << std::endl;
		sort::bubbleSort(strVector.begin(), strVector.end(), true, std::greater<>());
	}
	else if (typeSort == "2" && orderBy == "1")
	{
		std::cout << "insertion sort(ascent):" << std::endl;
		sort::insertionSort(strVector.begin(), strVector.end(), true);
	}
	else if (typeSort == "2" && orderBy == "2")
	{
		std::cout << "insertion sort(descent):" << std::endl;
		sort::insertionSort(strVector.begin(), strVector.end(), true, std::greater<>());
	}
	else if (typeSort == "3" && orderBy == "1")
	{
		std::cout << "selection sort(ascent):" << std::endl;
		sort::selectionSort(strVector.begin(), strVector.end(), true);
	}
	else if (typeSort == "3" && orderBy == "2")
	{
		std::cout << "selection sort(descent):" << std::endl;
		sort::selectionSort(strVector.begin(), strVector.end(), true, std::greater<>());	
	}
}

int main()
{
	console();
	// int test[10] = {5,6,8,9,4,11,0,45,100,14};
	// int test[10] = {6,5,8,9,4,11,0,45,100,14};
	// sort::display(std::begin(test), std::end(test));
	// // sort::bubbleSort(std::begin(test), std::end(test), true, std::greater<>());
	// // sort::bubbleSort(std::begin(test), std::end(test), true);
	// // sort::selectionSort(std::begin(test), std::end(test), true, std::greater<>());
	// // sort::insertionSort(std::begin(test), std::end(test), true, std::greater<>());
	// sort::insertionSort(std::begin(test), std::end(test), true, std::greater<>());
	
	return (0);
}