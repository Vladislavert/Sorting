#include "SortManager.hpp"

#include <boost/algorithm/string.hpp>

#include "Sorting.hpp"

std::ostream& operator<<(std::ostream& out, const Date& date)
{
	out << date.day << "." << date.month << "." << date.year;
	return out;
}

SortManager::SortManager()
{
	sortTypes_ = {
		std::pair<std::string, sortType>("-1", sortType::NONE),
		std::pair<std::string, sortType>("1", sortType::BUBBLE),
		std::pair<std::string, sortType>("2", sortType::INSERT),
		std::pair<std::string, sortType>("3", sortType::SELECTION),
		std::pair<std::string, sortType>("4", sortType::QUICK),
		std::pair<std::string, sortType>("5", sortType::BINARY_HEAP)
	};
	orderBy_ = {
		std::pair<std::string, orderBy>("1", orderBy::ASC),
		std::pair<std::string, orderBy>("2", orderBy::DESC)
	};
	dataTypes_ = {
		std::pair<std::string, dataType>("-1", dataType::OTHER),
		std::pair<std::string, dataType>("1", dataType::INTEGER),
		std::pair<std::string, dataType>("2", dataType::DOUBLE),
		std::pair<std::string, dataType>("3", dataType::STRING),
		std::pair<std::string, dataType>("4", dataType::DATE),
	};
}

bool SortManager::start()
{
	std::string sortTypeString;
	std::string orderBy;
	std::string dataType;



	printSortType();
	getline(std::cin, sortParams_.selectSortType);
	std::vector<std::string> v1;
	std::string str;
	int length(0);
	if (selectedSortType() == false)
		return (false);
	printOrderBy();
	getline(std::cin, sortParams_.orderBy);
	printDataType();
	getline(std::cin , sortParams_.dataType);
	std::cout << "enter data:" << std::endl;
	getline(std::cin, str);

	boost::split(dataLine_, str, boost::is_any_of(" "));

	parse();

	return (true);
}

void SortManager::printSortType()
{
	std::cout << "enter sort type" << std::endl;
	std::cout << "1 - bubbleSort" << std::endl;
	std::cout << "2 - insertionSort" << std::endl;
	std::cout << "3 - selectionSort" << std::endl;
	std::cout << "4 - quickSort" << std::endl;
	std::cout << "5 - binaryHeap" << std::endl;
	std::cout << "6 - exit" << std::endl;
}

bool SortManager::selectedSortType()
{
	if (sortParams_.selectSortType == "1")
	{
		std::cout << "bubble sort:" << std::endl;
	}
	else if (sortParams_.selectSortType == "2")
	{
		std::cout << "insertion sort:" << std::endl;
	}
	else if (sortParams_.selectSortType == "3")
	{
		std::cout << "selection sort:" << std::endl;
	}
	else if (sortParams_.selectSortType == "4")
	{
		std::cout << "quick sort:" << std::endl;
	}
	else if (sortParams_.selectSortType == "5")
	{
		std::cout << "binary heap:" << std::endl;
	}
	else if (sortParams_.selectSortType == "6")
	{
		return (false);
	}
	else
	{
		commandNotFound(sortParams_.selectSortType);
		printSortType();
	}
	return (true);
}

void SortManager::commandNotFound(const std::string& cmd)
{
	std::cout << "command " << cmd << ": not found" << std::endl;
}

void SortManager::printOrderBy()
{
	std::cout << "order by" << std::endl;
	std::cout << "1 - ASC" << std::endl; // ascent(восхождение)
	std::cout << "2 - DESC" << std::endl; // descent(спуск)
}

void SortManager::printDataType()
{
	std::cout << "data type:" << std::endl;
	std::cout << "1 - INTEGER" << std::endl;
	std::cout << "2 - DOUBLE" << std::endl;
	std::cout << "3 - STRING" << std::endl;
	std::cout << "4 - DATE" << std::endl;
}

void SortManager::parse()
{
	if (dataTypes_[sortParams_.dataType] == dataType::INTEGER)
	{
		std::vector<int> data;

		data.reserve(dataLine_.size());
		for (auto & i : dataLine_)
		{
			data.push_back(std::stoi(i));
		}
		sortCall<int>(data);
	}
	else if (dataTypes_[sortParams_.dataType] == dataType::DOUBLE)
	{

		std::vector<double> data;

		data.reserve(dataLine_.size());
		for (auto & i : dataLine_)
		{
			data.push_back(std::stod(i));
		}
		sortCall<double>(data);
	}
	else if (dataTypes_[sortParams_.dataType] == dataType::STRING)
	{
		std::vector<std::string> data;

		data.reserve(dataLine_.size());
		for (auto & i : dataLine_)
		{
			data.push_back(i);
		}
		sortCall<std::string>(data);
	}
	else if (dataTypes_[sortParams_.dataType] == dataType::DATE)
	{
		std::vector<Date> data;

		data.reserve(dataLine_.size());
		for (auto & i : dataLine_)
		{
			data.push_back(parseDate(i));
		}
		sortCall<Date>(data);
	}
}

Date SortManager::parseDate(const std::string& data)
{
	Date retDate;

	std::vector<std::string> date;
	boost::split(date, data, boost::is_any_of(":"));
	retDate.day = std::stoi(date[0]);
	retDate.month = std::stoi(date[1]);
	retDate.year = std::stoi(date[2]);

	return (retDate);
}

