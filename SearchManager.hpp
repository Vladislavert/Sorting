#ifndef SEARCH_MANAGER_HPP_
#define SEARCH_MANAGER_HPP_

#include <map>

#include "ConsoleManager.hpp"
#include "Searching.hpp"
#include "Date.hpp"

enum class searchType
{
	NONE = 0,
	LINEAR_SEARCH,
	BINARY,
	BINARY_MODIFIED
};


struct SearchParams
{
	std::string searchType;
	std::string dataType;
};


class SearchManager : public ConsoleManager
{
	public:

		SearchManager();
		~SearchManager() override = default;

		bool    start();

	private:
		std::map<std::string, searchType> searchTypes_;
		std::map<std::string, dataType> dataTypes_;

		SearchParams				searchParams_;
		std::vector<std::string>	dataLine_;
		std::string					value_;
//		template<class T>
//		std::vector<T>	data_;
		void printSearchType();
		bool selectedSearchType();
		void parse();

		template<class T>
		void searchCall(std::vector<T> data, T val)
		{
			if (searchTypes_[searchParams_.searchType] == searchType::LINEAR_SEARCH)
			{
				if (search::linearSearch(data.begin(), data.end(), val))
					std::cout << "variable - " << val << " found";
				else
					std::cout << "variable - " << val << " not found";
			}
			else if (searchTypes_[searchParams_.searchType] == searchType::BINARY)
			{
				search::binarySearch(data.begin(), data.end(), val);
			}
//			else if (searchTypes_[searchParams_.searchType] == searchType::BINARY_MODIFIED)
//			{
//				search::insertionSort(data.begin(), data.end(), true);
//			}
		}
};

#endif // SEARCH_MANAGER_HPP_
