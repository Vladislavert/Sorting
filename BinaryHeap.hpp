#ifndef BINARY_SEARCH_HPP_
#define BINARY_SEARCH_HPP_

#include <iterator>

class BinarySearch
{
	public:
		BinarySearch() = default;
		~BinarySearch() = default;
	private:
		template<class Iterator, Compare cmp = std::less<>>
		void heapify(Iterator, Compare cmp = Compare());
};

#endif