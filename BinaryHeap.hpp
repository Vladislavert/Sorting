#ifndef BINARY_SEARCH_HPP_
#define BINARY_SEARCH_HPP_

#include <iterator>
#include <bits/stdc++.h>

class BinaryHeap {
    public:
        BinaryHeap() = default;
        ~BinaryHeap() = default;

        template<class Iterator, class Compare = std::less<>>
        void sort(Iterator begin, Iterator end, Compare cmp = Compare())
		{
			buildHeap(begin, end, cmp);
//			for (Iterator i = end; i >= begin; --i)
			for (int i = std::distance(begin, end) - 1; i >= 0; --i)
			{
				std::iter_swap(begin, std::next(begin, i));
				heapify(begin, end, 0, cmp);
			}
        }

		template<class Iterator, class Compare = std::less<>>
		void buildHeap(Iterator begin, Iterator end, Compare cmp = Compare())
		{
			for (int i = std::distance(begin, end) / 2; i >= 0; --i)
//			for (int i = std::distance(begin, end); i >= -1; --i)
			{
				heapify(begin, end, i, cmp);
			}
		}

        template<class Iterator, class Compare = std::less<>>
        void popHeap(Iterator begin, Iterator end, Compare cmp = Compare())
		{

        }

    private:
        int size_;

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
                if (left < end && !cmp(*left, *largest))
				{
                    largest = left;
                }
                if (right < end && !cmp(*right, *largest))
				{
                    largest = right;
                }
                if (largest == std::next(begin, i))
				{
                    break;
                }
                std::iter_swap(std::next(begin, i), largest);
//                i = largest;
				i = std::distance(begin, largest);
            }
        }

};

#endif