#include "SearchManager.hpp"

#include <boost/algorithm/string.hpp>

SearchManager::SearchManager()
{
	searchTypes_ = {
		std::pair<std::string, searchType>("-1", searchType::NONE),
		std::pair<std::string, searchType>("1", searchType::LINEAR_SEARCH),
		std::pair<std::string, searchType>("2", searchType::BINARY),
		std::pair<std::string, searchType>("3", searchType::BINARY_MODIFIED),
	};
	dataTypes_ = {
		std::pair<std::string, dataType>("-1", dataType::OTHER),
		std::pair<std::string, dataType>("1", dataType::INTEGER),
		std::pair<std::string, dataType>("2", dataType::DOUBLE),
		std::pair<std::string, dataType>("3", dataType::STRING),
		std::pair<std::string, dataType>("4", dataType::DATE),
	};
}

bool SearchManager::start()
{
	printSearchType();
	getline(std::cin, searchParams_.searchType);
	std::vector<std::string> v1;
	std::string str;
	int length(0);
	if (selectedSearchType() == false)
		return (false);
	printDataType();
	getline(std::cin , searchParams_.dataType);
	std::cout << "enter data:" << std::endl;
	getline(std::cin, str);

	boost::split(dataLine_, str, boost::is_any_of(" "));
	std::cout << "value search" << std::endl;
	getline(std::cin, value_);

	parse();

	return (true);
}

void SearchManager::printSearchType()
{
	std::cout << "enter search type" << std::endl;
	std::cout << "1 - linear search" << std::endl;
	std::cout << "2 - binary search" << std::endl;
	std::cout << "3 - binary search modified" << std::endl;
	std::cout << "4 - exit" << std::endl;
}

bool SearchManager::selectedSearchType()
{
	if (searchParams_.searchType == "1")
	{
		std::cout << "linear search:" << std::endl;
	}
	else if (searchParams_.searchType == "2")
	{
		std::cout << "binary search:" << std::endl;
	}
	else if (searchParams_.searchType == "3")
	{
		std::cout << "binary search modified:" << std::endl;
	}
	else if (searchParams_.searchType == "4")
	{
		return (false);
	}
	else
	{
		commandNotFound(searchParams_.searchType);
		printSearchType();
	}
	return (true);
}

void SearchManager::parse()
{
	if (dataTypes_[searchParams_.dataType] == dataType::INTEGER)
	{
		std::vector<int> data;

		data.reserve(dataLine_.size());
		for (auto & i : dataLine_)
		{
			data.push_back(std::stoi(i));
		}
		searchCall<int>(data, std::stoi(value_));
	}
	else if (dataTypes_[searchParams_.dataType] == dataType::DOUBLE)
	{

		std::vector<double> data;

		data.reserve(dataLine_.size());
		for (auto & i : dataLine_)
		{
			data.push_back(std::stod(i));
		}
		searchCall<double>(data, std::stod(value_));
	}
	else if (dataTypes_[searchParams_.dataType] == dataType::STRING)
	{
		std::vector<std::string> data;

		data.reserve(dataLine_.size());
		for (auto & i : dataLine_)
		{
			data.push_back(i);
		}
		searchCall<std::string>(data, value_);
	}
	else if (dataTypes_[searchParams_.dataType] == dataType::DATE)
	{
		std::vector<Date> data;

		data.reserve(dataLine_.size());
		for (auto & i : dataLine_)
		{
			data.push_back(Date::parseDate(i));
		}
		searchCall<Date>(data, Date::parseDate(value_));
	}
}

