#ifndef SORTING_HPP_
#define SORTING_HPP_

#include <iostream>
#include <iterator>
#include <vector>
#include <algorithm>

namespace sort
{
	template<class Iterator>
	void display(Iterator begin, Iterator end)
	{
		for (auto i = begin; i < end; i++)
		{
			std::cout << *i << " ";
		}
		std::cout << std::endl;
	}

	template<class Iterator, class Compare = std::less<>>
	void bubbleSort(Iterator begin, Iterator end, bool history = false, Compare cmp = Compare())
	{
		double countStep(0); 

		for (auto i = begin + 1; i < end; i++)
			for (auto j = begin; j < end - 1; j++)
			{
				if (cmp(*i, *j))
				{
					std::iter_swap(i, j);
				}
				if (history == true)
				{
					std::cout << "Step " << countStep << ": ";
					display(begin, end);
					std::cout << std::endl;
					countStep++;
				}
			}
	}

	template<class Iterator, class Compare = std::less<>>
	void selectionSort(Iterator begin, Iterator end, bool history = false, Compare cmp = Compare())
	{
		double countStep(0);
		Iterator temp;
		Iterator j = begin + 1;

		for (auto i = begin; i < end - 1; i++)
		{
			temp = i;
				temp = std::min_element(i, end, cmp);
			std::iter_swap(i, temp);
			// j++;
			if (history == true)
			{
				std::cout << "Step " << countStep << ": ";
				display(begin, end);
				std::cout << std::endl;
				countStep++;
			}
		}
	}

	template<class Iterator, class Compare = std::less<>>
	void insertionSort(Iterator begin, Iterator end, bool history = false, Compare cmp = Compare())
	{
		double		countStep(0);
		Iterator	sorted;
		Iterator	j = begin + 1;

		for (auto i = begin; i < end - 1; ++i)
		{
			sorted = i;
			while (sorted >= begin && cmp(*(sorted + 1), *sorted))
			{
				std::iter_swap(sorted, sorted + 1);
				--sorted;
			}
			++j;
			if (history == true)
			{
				std::cout << "Step " << countStep << ": ";
				display(begin, end);
				std::cout << std::endl;
				countStep++;
			}
		}
	}

};

#endif // SORTING_HPP_