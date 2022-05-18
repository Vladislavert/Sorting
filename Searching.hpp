//
// Created by vladislav on 5/5/22.
//

#ifndef SEARCH_HPP_
#define SEARCH_HPP_

#include <iostream>
#include <iterator>
#include <vector>
#include <algorithm>

namespace search
{
	template<class ForwardInterator, class Tp, class BinaryPredicate = std::equal_to<>>
	bool linearSearch(ForwardInterator begin, ForwardInterator end, const Tp& val, BinaryPredicate predicate = BinaryPredicate())
	{
		double countStep(0);

		for (auto i = begin; i < end; i++)
		{
			if (predicate(*i, val))
			{
				return (true);
			}
		}
		return (false);
	}

//	template<typename ForwardIterator, typename Tp, typename CompareLess = std::less<>, typename CompareGreater = std::greater<>>
//	bool lowerBound(ForwardIterator first, ForwardIterator last,
//	                const Tp& val, CompareLess compLess = CompareLess(), CompareGreater compGreater = CompareGreater())
//	{
//		ForwardIterator low = first;
//		ForwardIterator high = last - 1;
//		ForwardIterator middle = first;
//
//		while (low <= high)
//		{
//			middle =  std::next(first, ((std::distance(first, low) + std::distance(first, high)) / 2));
//			if (compLess(val, *middle))
//			{
//				high = middle - 1;
//			}
//			else if (compGreater(val, *middle))
//			{
//				low = middle + 1;
//			}
//			else
//				return (true);
//		}
//
//		return (false);
//	}

	template<typename ForwardIterator, typename Tp, typename CompareLess = std::less<>, typename CompareGreater = std::greater<>>
	ForwardIterator lowerBound(ForwardIterator first, ForwardIterator last,
	                const Tp& val, CompareLess compLess = CompareLess(), CompareGreater compGreater = CompareGreater())
	{
		ForwardIterator low = first;
		ForwardIterator high = last - 1;
		ForwardIterator middle = first;

		while (low <= high)
		{
			middle =  std::next(first, ((std::distance(first, low) + std::distance(first, high)) / 2));
			if (compLess(val, *middle))
			{
				high = middle - 1;
			}
			else if (compGreater(val, *middle))
			{
				low = middle + 1;
			}
			else
				return (middle);
		}

		return (middle + 1);
	}

	template<class ForwardIterator, class Tp, class BinaryPredicate = std::equal_to<>>
	bool binarySearch(ForwardIterator first, ForwardIterator last,
	                  const Tp& val, BinaryPredicate predicate = BinaryPredicate())
	{
		ForwardIterator low = first;
		ForwardIterator high = last - 1;
		ForwardIterator middle = first;

		ForwardIterator ret = lowerBound(first, last, val);

		return (ret != last && val >= *ret);
//
	}

	template<class ForwardIterator, class Tp, class BinaryPredicate = std::equal_to<>>
	bool insertBinarySearch(ForwardIterator first, ForwardIterator last,
	                  const Tp& val, BinaryPredicate predicate = BinaryPredicate())
	{
		ForwardIterator low = first;
		ForwardIterator high = last - 1;
		ForwardIterator middle = first;


		ForwardIterator ret = lowerBound(first, last, val);

		return (ret);
	}

}; // namespace search


#endif // SEARCH_HPP_
