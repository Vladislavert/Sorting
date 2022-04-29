#ifndef BINARY_SEARCH_HPP_
#define BINARY_SEARCH_HPP_

#include <iterator>
#include <bits/stdc++.h>
#include <iostream>

class BinaryHeap {
    public:
        BinaryHeap() = default;
        ~BinaryHeap() = default;

        template<class Iterator, class Compare = std::less<>>
        void sort(Iterator begin, Iterator end, Compare cmp = Compare())
		{
			buildHeap(begin, end, cmp);
			for (int i = std::distance(begin, end) - 1; i > 0; --i)
			{
				std::iter_swap(begin, std::next(begin, i));
				heapify(begin, std::next(begin, i), 0, cmp);
			}

			std::cout << "result sort:" << std::endl;
			display(begin, end);
        }

		template<class Iterator, class Compare = std::less<>>
		void buildHeap(Iterator begin, Iterator end, Compare cmp = Compare())
		{
			for (int i = std::distance(begin, end) / 2; i >= 0; --i)
			{
				heapify(begin, end, i, cmp);
			}
		}

        template<class Iterator, class Compare = std::less<>>
        void popHeap(Iterator begin, Iterator end, Compare cmp = Compare())
		{

        }

		template<class Iterator>
		void display(Iterator begin, Iterator end)
		{
			for (auto i = begin; i < end; i++)
			{
				std::cout << *i << " ";
			}
			std::cout << std::endl;
		}

    private:

        /**
         *
         * @tparam Iterator
         * @tparam Compare
         * @param i
         * @param cmp
         */
        template<class Iterator, class Compare = std::less<>>
        void heapify(Iterator begin, Iterator end, int i, Compare cmp = Compare()) {
            Iterator left;
            Iterator right;
            Iterator largest;

            while (true)
			{
				left = std::next(begin, 2 * i + 1);
				right = std::next(begin, 2 * i + 2);
                largest = std::next(begin, i);
                if (left < end && cmp(*largest, *left))
				{
                    largest = left;
                }
                if (right < end && cmp(*largest, *right))
				{
                    largest = right;
                }
                if (largest == std::next(begin, i))
				{
                    break;
                }
                std::iter_swap(std::next(begin, i), largest);
				i = std::distance(begin, largest);
            }
        }

};

#endif