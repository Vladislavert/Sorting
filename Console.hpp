#ifndef CONSOLE_HPP_
#define CONSOLE_HPP_

#include <string>
#include <map>
#include <vector>
#include "Sorting.hpp"

enum class sortType
{
	NONE = 0,
	BUBBLE,
	INSERT,
	SELECTION,
	QUICK
};

enum class orderBy
{
	ASC = 0,
	DESC
};

enum class dataType
{
	OTHER = 0,
	INTEGER,
	DOUBLE,
	STRING,
	DATE
};

struct SortParams
{
	std::string selectSortType;
	std::string orderBy;
	std::string dataType;
};

struct Date
{
	int day;
	int month;
	int year;

	bool operator<(const Date& second) const
	{
		if (year < second.year)
			return true;

		if (year == second.year && month < second.month)
			return true;

		if (year == second.year && month == second.month && day < second.day)
			return true;

		return (false);
	}
	bool operator>(const Date& second) const
	{
		return (second < *this);
	}
};

std::ostream& operator<<(std::ostream& out, const Date& date);

class Console
{
    public:
		Console();
		~Console() = default;

        bool startConsole();

    private:
		std::map<std::string, sortType> sortTypes_;
		std::map<std::string, orderBy> orderBy_;
		std::map<std::string, dataType> dataTypes_;

		SortParams				sortParams_;
		std::vector<std::string>	dataLine_;
//		template<class T>
//		std::vector<T>	data_;
		void printSortType();
		void printOrderBy();
		void printDataType();
		void commandNotFound(const std::string& cmd);
		bool selectedSortType();
		Date parseDate(const std::string &data);
		void parse();
		template<class T>
		void sortCall(std::vector<T> data)
		{
			if (sortTypes_[sortParams_.selectSortType] == sortType::BUBBLE &&
				orderBy_[sortParams_.orderBy] == orderBy::ASC)
			{
				sort::bubbleSort(data.begin(), data.end(), true);
			}
			else if (sortTypes_[sortParams_.selectSortType] == sortType::BUBBLE &&
				orderBy_[sortParams_.orderBy] == orderBy::DESC)
			{
				sort::bubbleSort(data.begin(), data.end(), true, std::greater<>());
			}
			else if (sortTypes_[sortParams_.selectSortType] == sortType::INSERT &&
				orderBy_[sortParams_.orderBy] == orderBy::ASC)
			{
				sort::insertionSort(data.begin(), data.end(), true);
			}
			else if (sortTypes_[sortParams_.selectSortType] == sortType::INSERT &&
				orderBy_[sortParams_.orderBy] == orderBy::DESC)
			{
				sort::insertionSort(data.begin(), data.end(), true, std::greater<>());
			}
			else if (sortTypes_[sortParams_.selectSortType] == sortType::SELECTION &&
				orderBy_[sortParams_.orderBy] == orderBy::ASC)
			{
				sort::selectionSort(data.begin(), data.end(), true);
			}
			else if (sortTypes_[sortParams_.selectSortType] == sortType::SELECTION &&
				orderBy_[sortParams_.orderBy] == orderBy::DESC)
			{
				sort::selectionSort(data.begin(), data.end(), true, std::greater<>());
			}
			else if (sortTypes_[sortParams_.selectSortType] == sortType::QUICK &&
				orderBy_[sortParams_.orderBy] == orderBy::ASC)
			{
				sort::quickSort(data.begin(), data.end(), true);
			}
			else if (sortTypes_[sortParams_.selectSortType] == sortType::QUICK &&
				orderBy_[sortParams_.orderBy] == orderBy::DESC)
			{
				sort::quickSort(data.begin(), data.end(), true, std::greater<>());
			}
		}
};

#endif // CONSOLE_HPP_