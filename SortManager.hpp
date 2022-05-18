#ifndef SORT_MANAGER_HPP_
#define SORT_MANAGER_HPP_

#include "Sorting.hpp"
#include "ConsoleManager.hpp"

enum class sortType
{
	NONE = 0,
	BUBBLE,
	INSERT,
	SELECTION,
	QUICK,
	BINARY_HEAP
};

enum class orderBy
{
	ASC = 0,
	DESC
};

struct SortParams
{
	std::string selectSortType;
	std::string orderBy;
	std::string dataType;
};

class SortManager : public ConsoleManager
{
	public:

		SortManager();
		~SortManager() override = default;

		bool    start();

	private:
		std::map<std::string, sortType> sortTypes_;
		std::map<std::string, orderBy>  orderBy_;
		std::map<std::string, dataType> dataTypes_;

		SortParams				    sortParams_;
		std::vector<std::string>	dataLine_;
//		template<class T>
//		std::vector<T>	data_;
		void printSortType();
		void printOrderBy();
		bool selectedSortType();
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
			else if (sortTypes_[sortParams_.selectSortType] == sortType::BINARY_HEAP &&
				orderBy_[sortParams_.orderBy] == orderBy::ASC)
			{
				sort::binaryHeap(data.begin(), data.end(), true);
			}
			else if (sortTypes_[sortParams_.selectSortType] == sortType::BINARY_HEAP &&
				orderBy_[sortParams_.orderBy] == orderBy::DESC)
			{
				sort::binaryHeap(data.begin(), data.end(), true, std::greater<>());
			}
		}
};

#endif // SORT_MANAGER_HPP_